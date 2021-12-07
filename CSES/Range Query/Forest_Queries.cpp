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
    ll n, m;
    cin >> n;
    m = n;
    ll q;
    cin >> q;
    vector<ll> a[n];
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++) {
            if (s[j] == '*')
                a[i].push_back(1);
            else
                a[i].push_back(0);
        }
    }
    vector<vector<ll>> pre(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            pre[i][j] = a[i][j];
            if (i > 0) pre[i][j] += pre[i - 1][j];
            if (j > 0) pre[i][j] += pre[i][j - 1];
            if (i > 0 and j > 0) pre[i][j] -= pre[i - 1][j - 1];
        }
    }
    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        ll ans = pre[x2][y2];
        if (y1 > 0) {
            ans -= pre[x2][y1 - 1];
        }
        if (x1 > 0) {
            ans -= pre[x1 - 1][y2];
        }
        if (x1 > 0 and y1 > 0) {
            ans += pre[x1 - 1][y1 - 1];
        }
        cout << ans << '\n';
    }
}