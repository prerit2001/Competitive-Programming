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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}


/*
	Observation1 : Back-Edge is never a Bridge
	Observation2 : Bridge -> backedge in the substree of source do not connects to any of
							 the ancestor of source 
*/


/*https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/*/
void dfs(ll src, ll par, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& lvl, vector<ll>& dp, vector<pair<ll,ll>>& bridge, vector<ll>& articulationPoint){
	vis[src] = 1;
	bool ok = 1; // articulation point finding
	par == -1 ? lvl[src] = 0LL : lvl[src] = lvl[par] + 1;
	dp[src] = lvl[src];
	for(auto &next: adj[src]){
		if(next == par) continue;
		if(vis[next] == 1) dp[src] = min(dp[src], lvl[next]);
		else{
			dfs(next, src, adj, vis, lvl, dp, bridge, articulationPoint);
			dp[src] = min(dp[src], dp[next]);
			ok &= dp[next] < lvl[src];
			if(dp[next] > lvl[src]){
				bridge.push_back({min(src, next), max(src, next)}); // found a bridge B/W (srn <-> next)
			}
		}
	}
	if(!ok and adj[src].size() > 1) articulationPoint.push_back(src);
}

void solve() {
	ll n; cin >> n;
	vector<vector<ll>> adj(n);
	ll m; cin >> m;
	for(ll i = 0; i < m; i ++){
		ll u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n);
	vector<ll> dp(n, 0), lvl(n, 0);
	vector<ll> articulationPoint;
	vector<pair<ll,ll>> bridge; 
	for(ll i = 0; i < n; i ++){
		if(vis[i] == 0){
			dfs(i, -1, adj, vis, lvl, dp, bridge, articulationPoint);
		}
	}
	cout << articulationPoint.size() << '\n';
	sort(all(articulationPoint));
	for(auto &it: articulationPoint){
		cout << it << " ";
	}
	cout << '\n';
	cout << bridge.size() << '\n';
	sort(all(bridge));
	for(auto it: bridge) {
		cout << it.first << " " << it.second << '\n';
	}
}