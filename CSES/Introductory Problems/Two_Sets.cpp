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
    ll sum = n * (n + 1) / 2;
    if (sum % 2 == 0) {
        sum = sum / 2;
        vector<ll> a, b;
        for (ll i = n; i >= 1; i--) {
            if (sum - i >= 0) {
                sum -= i;
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        cout << "YES\n";
        cout << a.size() << '\n';
        for (auto &it : a) cout << it << " ";
        cout << '\n';
        cout << b.size() << '\n';
        for (auto &it : b) cout << it << " ";
    } else {
        cout << "NO";
    }
}