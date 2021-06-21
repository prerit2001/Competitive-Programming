/*
 // Prim Spanning Tree
*/

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int N,M;

const int LIMIT = 1e5+5;
vector<pair<int,int>> adj[LIMIT];
bool vis[LIMIT];

int ans = 0;

void prim_minimum_spanning_tree(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.push({0,0});
	while(!Q.empty()){
		auto u = Q.top();
		Q.pop();
		if(vis[u.second]){
			continue;
		}
		ans += u.first;
		vis[u.second] = 1;
		for(auto [v,w] : adj[u.second]){
			if(!vis[v]){
				Q.push({w,v});
			}
		}
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n,m; cin >> n >> m;
		N = n, M = m;

		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
			adj[v-1].push_back({u-1,w});
		}

		memset(vis,false,sizeof(vis));

		prim_minimum_spanning_tree();

		// check if any disconnected component
		for(i=0;i<n;i++){
			if(!vis[i]){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}

		cout << ans << '\n';
	}	
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
