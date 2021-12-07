#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef int ll;
ll power(ll x, ll y, ll mod) {
    ll res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
void solve();
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

mt19937 mt;
struct node {
    ll p, v, s;
    node *l, *r;
    node(ll x) : p(x), v(mt()), s(1) { l = r = nullptr; }
    void pull() { s = 1 + (l ? l->s : 0) + (r ? r->s : 0); }
};

class Treap {
   public:
    node* merge(node* a, node* b) {
        if (!a || !b) return a ?: b;
        if (a->v < b->v)
            return a->r = merge(a->r, b), a->pull(), a;
        else
            return b->l = merge(a, b->l), b->pull(), b;
    }

    void split(node* cur, ll k, node*& a, node*& b) {
        if (!cur) {
            a = b = nullptr;
            return;
        }
        if (cur->p < k)
            a = cur, split(a->r, k, a->r, b), a->pull();
        else
            b = cur, split(b->l, k, a, b->l), b->pull();
    }

    void insert(node*& cur, ll x) {
        node *l, *r;
        split(cur, x, l, r);
        cur = merge(merge(l, new node(x)), r);
    }

    void erase(node*& cur, ll x) {
        node *l, *m, *r;
        split(cur, x, l, m);
        split(m, x + 1, m, r);
        if (m)
            cur = merge(merge(l, merge(m->l, m->r)), r);
        else
            cur = merge(l, r);
    }

    ll strictly_less_than_custom(node*& cur, ll x) {
        node *l, *r;
        split(cur, x, l, r);
        ll ans = (l ? l->s : 0);
        cur = merge(l, r);
        return ans;
    }

    // let max value of a[i] be 1e10
    ll find_by_order2(node*& cur, ll x, ll n) {  // 1 indexed // (logn)^2
        if (x < 1 or x > n) return -1;
        x--;
        ll left = 1, right = 1e9 + 1;
        ll ans = -1;
        while (left < right) {
            ll mid = (left + right) >> 1;
            ll val = strictly_less_than_custom(cur, mid);
            if (val > x) {
                right = mid;
            } else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }

    void splitPos(node* cur, ll k, node*& a, node*& b, ll add = 0) {
        if (!cur) {
            a = b = nullptr;
            return;
        }
        ll idx = add + (cur->l ? cur->l->s : 0);
        if (idx < k)
            a = cur, splitPos(a->r, k, a->r, b, idx + 1), a->pull();
        else
            b = cur, splitPos(b->l, k, a, b->l, add), b->pull();
    }

    ll find_by_order(node*& cur, ll x, ll n) {  // 0 indexed // logn
        node *l, *m, *r;
        splitPos(cur, x, l, m);
        splitPos(m, 1, m, r);
        ll ans = -1;
        if (m) {
            ans = m->p;
        }
        cur = merge(l, merge(m, r));
        return ans;
    }

    ll order_of_key(node*& cur, ll x) {  // 1 indexed
        node *l, *m, *r;
        split(cur, x, l, m);
        split(m, x + 1, m, r);
        ll ans = -1;
        if (m) {  // possible
            ans = 1 + (l ? l->s : 0);
        }
        cur = merge(l, merge(m, r));
        return ans;
    }
};

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    node* root = nullptr;
    Treap t;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        t.insert(root, i + 1);
    }
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll v = t.find_by_order(root, x - 1, n);  // accept 0 indexed
        cout << a[v - 1] << " ";
        t.erase(root, v);
    }
}