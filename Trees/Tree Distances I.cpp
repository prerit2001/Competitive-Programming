#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 2e5+5;
vector<int> adj[limit];
bool vis[limit];
int dist[limit] = {};

pair<int,int> bfs(int curr, int ok = 0){
	queue<pair<int,int>> q;
	q.push({curr,0});
	pair<int,int> ans;
	vis[curr] = 1;
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		ans = u;
		if(ok) dist[u.first] = max(dist[u.first],u.second);
		for(auto v : adj[u.first]){
			if(!vis[v]){
				vis[v] = 1;
				q.push({v,u.second+1});
			}
		}
	}
	return ans;
}

void solve(){
	int i,j;
	int n; cin >> n;
	for(i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	memset(vis,0, sizeof vis);
	auto d1 = bfs(0);
	memset(vis,0, sizeof vis); 
	auto d2 = bfs(d1.first);

	// d1 and d2 are two diametric end we always has max lenth from any node to either of the two diametric node

	memset(vis,0, sizeof vis);
	auto x = bfs(d1.first,1);
	memset(vis,0, sizeof vis); 
	auto y = bfs(d2.first,1);

	for(i=0;i<n;i++){
		cout << dist[i] << " ";
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int64_t t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}