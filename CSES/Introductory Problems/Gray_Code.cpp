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
    for (int i = 0; i < (1 << n); i++) {
        int num = (i ^ (i >> 1));
        bitset<32> r(num);
        for (ll j = n - 1; j >= 0; j--) cout << r[j];
        cout << '\n';
    }
}