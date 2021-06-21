#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 2e5+5;
vector<int> adj[limit];
bool vis[limit];
int up[limit][33];
int starttime[limit];
int endtime[limit];
int timer = 0;
int dist[limit];

void binary_lifting_dfs(int source, int parent){
	up[source][0] = parent;
	for(int i=1;i<=32;i++){
		if(up[up[source][i-1]][i-1] != -1) up[source][i] = up[up[source][i-1]][i-1];
		else up[source][i] = -1;
	}
	for(auto v : adj[source]){
		if(v != parent){
			binary_lifting_dfs(v,source);
		}
	}
}

void dfs(int curr, int level = 0){
	vis[curr]=1;
	timer++;
	starttime[curr] = timer;
	dist[curr] = level;
	for(auto v : adj[curr]){
		if(!vis[v]){
			dfs(v,level+1);
		}
	}
	timer++;
	endtime[curr] = timer;
}

int lca(int a, int b){
	if(starttime[a] <= starttime[b] and endtime[a] >= endtime[b]) return a;
	if(starttime[b] <= starttime[a] and endtime[b] >= endtime[a]) return b;
	for(int i=20;i>=0;i--){
		if(!(up[a][i] == -1 or (starttime[up[a][i]] <= starttime[b] and endtime[up[a][i]] >= endtime[b]))){
			a = up[a][i];
		} 
	}
	return up[a][0];
}

void solve(int i = 0, int j = 0){
	int n,q; cin >> n >> q;
	for(i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	binary_lifting_dfs(0,-1);
	memset(vis, 0, sizeof vis);
	dfs(0);
	while(q --){
		int a,b; cin >> a >> b;
		a --, b --;
		int LCA = lca(a,b);
		int ans = (dist[a] - dist[LCA]) + (dist[b] - dist[LCA]);
		cout << ans << '\n';
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t = 1;
	// cin>>t;
	while(t --){
		solve();
	}
	
}