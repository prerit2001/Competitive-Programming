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
    ll a[26] = {};
    ll n = s.size();
    for (ll i = 0; i < n; i++) {
        a[s[i] - 'A']++;
    }
    ll oddF = 0;
    for (ll i = 0; i < 26; i++) {
        oddF += a[i] % 2;
    }
    if (oddF > 1) {
        cout << "NO SOLUTION";
    } else {
        ll l = 0, r = n - 1;
        ll store = -1;
        for (ll i = 0; i < 26; i++) {
            if (a[i] % 2) {
                store = i;
            } else {
                while (a[i] > 0) {
                    a[i] -= 2;
                    s[l++] = 'A' + i;
                    s[r--] = 'A' + i;
                }
            }
        }
        if (store != -1) {
            while (a[store] > 0) {
                a[store] -= 1;
                s[l++] = 'A' + store;
            }
        }
        cout << s << '\n';
    }
}