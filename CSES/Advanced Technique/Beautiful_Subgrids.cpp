#include <bits/stdc++.h>
#pragma GCC target("popcnt")
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

ll val(ll n) { return n * (n - 1) / 2; }

void solve() {
    ll n;
    cin >> n;
    bitset<3000> b[n];
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    for (ll j = 0; j < n; j++) {
        for (ll i = j + 1; i < n; i++) {
            ans += val((b[i] & b[j]).count());
        }
    }
    cout << ans;
}