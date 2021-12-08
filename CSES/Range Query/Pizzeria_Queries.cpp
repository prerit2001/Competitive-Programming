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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    vector<ll> store(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
        a[i] = store[i];
        b[i] = store[i];
        a[i] -= (i + 1);
        b[i] += (i + 1);
    }
    segTree segL(n, a), segR(n, b);
    while (q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            ll p, x;
            cin >> p >> x;
            segL.update(1, 1, n, p, x - p);
            segR.update(1, 1, n, p, x + p);
        } else {
            ll x;
            cin >> x;
            ll leftMin = segL.query(1, 1, n, 1, x) + x;
            ll rightMin = segR.query(1, 1, n, x, n) - x;
            cout << min(leftMin, rightMin) << '\n';
        }
    }
}