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

void solve() {
    ll n;
    cin >> n;
    cout << 0 << '\n';
    for (ll i = 2; i <= n; i++) {
        ll total = i * i * (i * i - 1) / 2;
        if (i > 2) {
            ll m1 = (i - 1) * (i - 2) * 4;
            total -= m1;
        }
        cout << total << '\n';
    }
}