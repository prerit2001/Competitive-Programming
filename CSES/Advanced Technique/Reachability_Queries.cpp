#include <bits/stdc++.h>
#pragma GCC target("popcnt")
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

const ll N = 5e4 + 5;
vector<ll> adj[N];
vector<bool> vis(N, 0);
vector<ll> reach(N, 0);
bitset<N> b[N];

void dfs(ll curr) {
    vis[curr] = 1;
    bool isIn = 0;
    reach[curr] = 1;
    b[curr].set(curr);
    for (auto &it : adj[curr]) {
        if (!vis[it]) {
            isIn = 1;
            dfs(it);
        }
        b[curr] |= b[it];
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll q;
    cin >> q;
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (ll i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        cout << (b[u - 1].test(v - 1) ? "YES" : "NO") << '\n';
    }
}