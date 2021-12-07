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
    if (n <= 3 and n >= 2) {
        cout << "NO SOLUTION";
        return;
    }
    if (n == 4) {
        cout << "2 4 1 3";
        return;
    }
    for (ll i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    for (ll i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
}