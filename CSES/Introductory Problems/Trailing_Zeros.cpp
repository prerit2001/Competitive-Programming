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
    ll ans = 0;
    ll p = 0, i;
    ll minus = 0;
    for (ll i = log(n) / (log(5)); i >= 1; i--) {
        ll curr = n / power(5, i, 1e9 + 7);
        curr -= minus;
        ans += curr * i;
        minus += curr;
    }
    cout << ans;
}