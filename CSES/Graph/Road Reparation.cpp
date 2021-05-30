/*
 // Prim Spanning Tree
*/

#include<bits/stdc++.h>
using namespace std;

int64_t N,M;

const int64_t LIMIT = 1e5+5;
vector<pair<int64_t,int64_t>> adj[LIMIT];
bool vis[LIMIT];

int64_t ans = 0;

void prim_minimum_spanning_tree(){
	priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
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

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n,m; cin >> n >> m;
		N = n, M = m;

		for(i=0;i<m;i++){
			int64_t u,v,w; cin >> u >> v >> w;
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


// Krushkal's also works