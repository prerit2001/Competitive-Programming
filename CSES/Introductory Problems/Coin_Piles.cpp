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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (2 * a < b) {
        cout << "NO\n";
        return;
    }
    a = a % 3;
    b = b % 3;
    if (a > b) swap(a, b);
    if (a == 1 and b == 2) {
        cout << "YES\n";
        return;
    }
    if (a + b == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}