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
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        char c = s[i];
        ll cnt = 0;
        while (i < n and s[i] == c) i++, cnt++;
        i--;
        ans = max(cnt, ans);
    }
    cout << ans;
}