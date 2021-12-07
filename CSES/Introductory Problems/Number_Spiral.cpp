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
    ll x, y;
    cin >> x >> y;
    if (x >= y) {
        if (x % 2 == 0) {
            cout << x * x - (y - 1);
        } else {
            cout << (x - 1) * (x - 1) + 1 + (y - 1);
        }
    } else {
        if (y % 2 == 0) {
            cout << (y - 1) * (y - 1) + 1 + (x - 1);
        } else {
            cout << y * y - (x - 1);
        }
    }
    cout << '\n';
}