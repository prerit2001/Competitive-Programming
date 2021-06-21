#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 2e5+5;
vector<int> adj[limit];
bool vis[limit];

pair<int,int> bfs(int curr){
	queue<pair<int,int>> q;
	q.push({curr,0});
	pair<int,int> ans;
	vis[curr] = 1;
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		ans = u;
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
	// the node which has largest distance must be one of the diameter
	memset(vis,0, sizeof vis);
	auto d1 = bfs(0);
	// now again bfs from d1 results in d2, thats what we want
	memset(vis,0, sizeof vis); 
	auto d2 = bfs(d1.first);
	cout << d2.second << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int64_t t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}