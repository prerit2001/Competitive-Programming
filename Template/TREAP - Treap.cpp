
// // Treap 1 : https://cses.fi/problemset/task/1749/
 
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
 
    ll find_by_order(node*& cur, ll x, ll n) {
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
        ll v = t.find_by_order(root, x - 1, n);
        cout << a[v - 1] << " ";
        t.erase(root, v);
    }
}

// ----------------------------------------------------------------

// Treap 2 : https://cses.fi/problemset/task/1144/


#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
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
int main() {
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
    int p, v, s;
    node *l, *r;
    node(int x) : p(x), v(mt()), s(1) { l = r = nullptr; }
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
 
    ll find_by_order(node*& cur, ll x, ll n) {
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
    ll q;
    cin >> q;
    vector<ll> a(n);
    node* root = nullptr;
    Treap t;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        t.insert(root, a[i]);
    }
    while (q--) {
        char c;
        cin >> c;
        ll l, r;
        cin >> l >> r;
        if (c == '!') {
            t.erase(root, a[l - 1]);
            a[l - 1] = r;
            t.insert(root, a[l - 1]);
        } else {
            node *left, *mid, *right;
            t.split(root, l, left, mid);
            t.split(mid, r + 1, mid, right);
            cout << (mid ? mid->s : 0) << '\n';
            root = t.merge(left, mid);
            root = t.merge(root, right);
        }
    }
}


// Treap 3 : https://cses.fi/problemset/task/2074/

#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    ll value;
    ll sz;
    ll prior;
    ll sum;
    node *l;
    node *r;
    bool rev;
    node(ll value){
        this -> value = value;
        this -> sz = 1;
        this -> prior = rng();
        this -> sum = value;
        this -> rev = 0;
        this -> l = nullptr;
        this -> r = nullptr;
    }
};

ll sz(node *x){
    return x ? x -> sz : 0ll;
}

ll sum(node *x){
    return x ? x -> sum : 0ll;
}

void recalc(node *x){
    assert(x);
    x -> sz = 1 + sz(x -> l) + sz(x -> r);
    x -> sum = x -> value + sum(x -> l) + sum(x -> r);
}

void push(node* x) {
  if (!x) return;
  if (x->rev) {
    swap(x->l, x->r);
    if (x->l) x->l->rev ^= true;
    if (x->r) x->r->rev ^= true;
    x->rev = false;
  }
}

node* merge(node* l, node* r) {
    push(l);
    push(r);
    if (!l) return r;
    if (!r) return l;
    if (l->prior < r->prior) {
        l->r = merge(l->r, r);
        recalc(l);
        push(l);
        return l;
    }
    else{
        r->l = merge(l, r->l);
        recalc(r);
        push(r);
        return r;
    }
}

pair<node*, node*> split(node* x, ll k){
    push(x);
    if (!x) {
        return {nullptr, nullptr};
    }
    if (k <= sz(x->l)) {
        pair<node*, node*> p = split(x->l, k);
        node* l = p.first;
        node* r = p.second;
        x->l = r;
        recalc(x);
        push(x);
        return make_pair(l, x);
    }
    else{
        pair<node*, node*> p = split(x->r, k - sz(x->l) - 1);
        node* l = p.first;
        node* r = p.second;
        x->r = l;
        recalc(x);
        push(x);
        return make_pair(x, r);
    }
}

void solve() {
    ll n; cin >> n;
    ll q; cin >> q;
    vector<ll> v(n);
    for(auto &it : v) cin >> it;
    node* root = nullptr;
    for(auto &it : v) root = merge(root, new node(it));
    while(q --){
        ll type, l, r; cin >> type >> l >> r;
        if(type == 1){ // reverse subarray
            pair<node*, node*> p1 = split(root, l - 1);
            pair<node*, node*> p2 = split(p1.second, r - l + 1);
            p2.first -> rev ^= 1;
            root = merge(p1.first, p2.first);
            root = merge(root, p2.second);
        }
        else { // sum subarray
            pair<node*, node*> p1 = split(root, l - 1);
            pair<node*, node*> p2 = split(p1.second, r - l + 1);
            cout << sum(p2.first) << '\n';
            root = merge(p1.first, p2.first);
            root = merge(root, p2.second);
        }
    }
}