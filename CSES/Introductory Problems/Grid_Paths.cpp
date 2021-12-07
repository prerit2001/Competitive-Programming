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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char cc[4] = {'R', 'L', 'U', 'D'};
ll ans = 0;

ll cnt = 0;
ll aa = 0;

void go(ll i, ll j, string p, string path, set<pair<ll, ll>> ss) {
    // cout << p.size() << '\n';
    if (cnt++ > 1000000) return;
    // cout << i << " " << j << '\n';
    if (p.size() == 48) {
        bool ok = 1;
        // for (ll i = 0; i < 48; i++) {
        //     if (p[i] != path[i] and path[i] != '?') {
        //         ok = 1;
        //         break;
        //     }
        // }
        ans += ok;
        cout << p << '\n';
    }
    for (ll x = 0; x < 4; x++) {
        ll xx = i + dx[x];
        ll yy = j + dy[x];
        if (xx < 0 or yy < 0 or xx >= 7 or yy >= 7) {
            continue;
        }
        if (ss.count({xx, yy})) continue;
        ss.insert({xx, yy});
        go(xx, yy, p + cc[x], path, ss);
        ss.erase({xx, yy});
    }
}

void solve() {
    string s;
    cin >> s;
    set<pair<ll, ll>> ss;
    ss.insert({0, 0});
    string k;
    go(0, 0, k, s, ss);
    cout << ans;
}