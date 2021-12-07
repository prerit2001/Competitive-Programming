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

ll go(ll i, ll n, vector<ll>& a, ll tot, ll sum = 0) {
    if (i == n) return abs(tot - sum - sum);
    return min(go(i + 1, n, a, tot, sum), go(i + 1, n, a, tot, sum + a[i]));
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto& it : a) cin >> it, sum += it;
    cout << go(0, n, a, sum);
}