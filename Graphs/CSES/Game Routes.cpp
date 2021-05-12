/*
 // Topological Sorting
*/

#include<bits/stdc++.h>
using namespace std;

int64_t N,M;

const int64_t LIMIT = 1e5 + 5;
vector<int64_t> adj[LIMIT];
bool vis[LIMIT];

int64_t indegree[LIMIT] = {};
deque<int64_t> topo_sort;

void dfs_topological_sort(int64_t src = 0){
	vis[src] = 1;
    for( auto &i : adj[src] ){
        if( !vis[i] ){
            dfs_topological_sort( i );
        }
    }
    topo_sort.push_front( src );
}

void dfs(int64_t src){
	vis[src] = 1;
	for(auto it : adj[src]){
		if(!vis[it]){
			dfs(it);
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
		 	int64_t u,v; cin >> u >> v;
		 	adj[u-1].push_back(v-1);
		 	indegree[v-1]++;
		 }	

 		 memset(vis,false,sizeof(vis));
		 dfs(0);
		 if(!vis[n-1]){
		 	cout << "0\n";
		 	continue;
		 }

		 // Dfs Based
		 memset(vis,false,sizeof(vis));
		 dfs_topological_sort();

		 int64_t parent[n],length[n] = {};
		 length[0] = 1;
		 memset(parent,0,sizeof(parent));
		 for(auto u : topo_sort){
		 	for(auto v : adj[u]){
		 		length[v]+=length[u]%(1000000007);
		 		length[v]%=(1000000007);
		 	}
		 }
		 cout << length[n-1]%(1000000007) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
