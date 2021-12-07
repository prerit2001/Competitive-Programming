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
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// range Min
class segTree {
   public:
    ll n;           // size of array
    vector<ll> a;   // 1-index array
    vector<ll> St;  // segTree Storage
    segTree(ll n, vector<ll> a) {
        this->n = n;
        this->a.resize(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            this->a[i + 1] = a[i];
        }
        St.resize(5 * n);
        build(1, 1, n);
    }
    void build(ll Si, ll Ss, ll Se) {
        if (Ss == Se) {
            St[Si] = a[Ss];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        build(2 * Si, Ss, mid);
        build(2 * Si + 1, mid + 1, Se);
        St[Si] = min(St[2 * Si], St[2 * Si + 1]);
    }
    ll query(ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
        if (Qs > Se or Qe < Ss) return 1e15;
        if (Qs <= Ss and Qe >= Se) return St[Si];
        ll mid = (Ss + Se) >> 1;
        ll lSubTree = query(2 * Si, Ss, mid, Qs, Qe);
        ll rSubTree = query(2 * Si + 1, mid + 1, Se, Qs, Qe);
        return min(lSubTree, rSubTree);
    }
    void update(ll Si, ll Ss, ll Se, ll q, ll val) {
        a[q] = val;
        if (Ss == Se) {
            St[Si] = a[Ss];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        if (Ss <= q and q <= mid)
            update(2 * Si, Ss, mid, q, val);
        else
            update(2 * Si + 1, mid + 1, Se, q, val);
        St[Si] = min(St[2 * Si], St[2 * Si + 1]);
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= -1;
    }
    segTree seg(n, a);
    for (ll i = 0; i < m; i++) {
        ll allMaxi = seg.query(1, 1, n, 1, n);
        allMaxi *= -1;
        ll x;
        cin >> x;
        if (allMaxi < x) {
            cout << 0 << " ";
        } else {
            ll l = 1, r = n;
            while (l < r) {
                ll mid = (l + r) >> 1;
                // {l ,mid}, {mid + 1, r}
                ll one = seg.query(1, 1, n, l, mid);
                one *= -1;
                if (one >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            cout << l << " ";
            a[l - 1] *= -1;
            a[l - 1] -= x;
            a[l - 1] *= -1;
            seg.update(1, 1, n, l, a[l - 1]);
        }
    }
}