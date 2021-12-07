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

vector<string> v(8);

vector<vector<string>> ans;
void go(int i, int n, vector<int> v, set<int> s, set<pair<int, int>> p) {
    if (i == n) {
        vector<string> a(n, string(n, '.'));
        for (int j = 0; j < n; j++) {
            a[j][v[j]] = '*';
        }
        ans.push_back(a);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (s.count(j)) continue;
        bool ok = 1;
        for (auto it : p) {
            ll x = it.first, y = it.second;
            if (x - i == y - j) {
                ok = 0;
                break;
            }
            if (x - i == j - y) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) continue;
        v.push_back(j);
        s.insert(j);
        p.insert({i, j});
        go(i + 1, n, v, s, p);
        p.erase({i, j});
        s.erase(j);
        v.pop_back();
    }
}

void solve() {
    for (ll i = 0; i < 8; i++) {
        cin >> v[i];
    }
    set<int> s;
    set<pair<int, int>> p;
    go(0, 8, {}, s, p);
    ll ans = 0;
    for (ll i = 0; i < ::ans.size(); i++) {
        bool ok = 1;
        for (ll j = 0; j < 8; j++) {
            for (ll k = 0; k < 8; k++) {
                if (::ans[i][j][k] == '*' and v[j][k] == '*') {
                    ok = 0;
                }
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
}