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

inline vector<ll> genrateSum(vector<ll>& a, ll n) {
    vector<ll> sum;
    for (ll i = 0; i < (1LL << n); i++) {
        ll temp = 0;
        ll p = 1;
        for (ll j = 0; j < n; j++) {
            if (i & p) {
                temp += a[j];
            }
            p *= 2;
        }
        sum.push_back(temp);
    }
    return sum;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    ll m = n / 2;
    n = n - m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<ll> A = genrateSum(a, n);
    vector<ll> B = genrateSum(b, m);
    ll ans = 0;
    sort(B.begin(), B.end());
    for (auto& it : A) {
        ans += upper_bound(all(B), x - it) - lower_bound(all(B), x - it);
    }
    cout << ans << '\n';
}