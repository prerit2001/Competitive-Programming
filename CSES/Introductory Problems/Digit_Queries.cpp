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

ll digit(ll n) {
    ll l = 9;
    ll sum = 0;
    ll cnt = 1;
    ll key = 0;
    while (sum + l <= n) {
        key += cnt * l;
        sum += l;
        cnt++;
        l *= 10;
    }
    key += cnt * (n - sum);
    return key;
}

void solve() {
    ll n;
    cin >> n;
    ll left = 1, right = 1e18;
    while (left < right - 1) {
        ll mid = (left + (right - left) / 2);
        ll d = digit(mid);
        if (d > n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    for (ll i = left; i <= right; i++) {
        ll d = digit(i);
        if (d >= n) {
            d = digit(i - 1);
            string s = to_string(i);
            cout << s[n - d - 1] << '\n';
            return;
        }
    }
}