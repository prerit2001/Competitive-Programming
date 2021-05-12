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


void bfs_toplogical_sort(){
	
	queue<int64_t> q;
	for(int i=0;i<N;i++){
		if(indegree[i] == 0 and vis[i]){
			q.push(i);
		}
	}

	int64_t cnt = 0;
	while(!q.empty()){
		cnt ++;
		int64_t curr = q.front();
		q.pop();
		topo_sort.push_back(curr);
		for(auto it : adj[curr]){
			if(--indegree[it] == 0){
				q.push(it);
			}
		}
	}
	
	// Graph has Cycle
	assert(cnt == N);
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
		 	cout << "IMPOSSIBLE\n";
		 	continue;
		 }


		 /*
		 // Don't Use Bfs Based Topo Sort Coz
		 // it might be possible than the next part
		 // is not reachable from previous one.
		 // bfs_toplogical_sort();
		 */


		 // Dfs Based
		 memset(vis,false,sizeof(vis));
		 dfs_topological_sort();

		 int64_t parent[n],length[n] = {};
		 memset(parent,0,sizeof(parent));
		 for(auto u : topo_sort){
		 	for(auto v : adj[u]){
		 		if(length[u]+1 > length[v]){
		 			length[v] = length[u] + 1;
		 			parent[v] = u;
		 		}
		 	}
		 }

		 cout << length[n-1] + 1 << '\n';
		 vector<int64_t> ans;
		 int64_t curr = n-1;
		 ans.push_back(n-1);
		 while(parent[curr] != 0){
		 	curr = parent[curr];
		 	ans.push_back(curr);
		 }
		 ans.push_back(0);
		 reverse(ans.begin(), ans.end());

		 for(auto it : ans){
		 	cout << it+1 << " ";
		 }
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

/*
// All Path Dfs Based TLE
*/

// #include<bits/stdc++.h>
// using namespace std;

// int64_t N,M;

// const int64_t LIMIT = 1e5 + 5;
// vector<int64_t> adj[LIMIT];
// bool vis[LIMIT];

// int64_t indegree[LIMIT] = {};
// vector<int64_t> topo_sort;

// int64_t parent[LIMIT] = {};
// int64_t length[LIMIT] = {};
// int64_t store = 0;

// void dfs(int64_t src){
// 	vis[src] = 1;
// 	if(src == N-1){
// 		store = max(length[src],store);
// 	}
// 	for(auto it : adj[src]){
// 		if(!vis[it]){
// 			length[it] = length[src] + 1;
// 			dfs(it);
// 		}
// 	}
// 	vis[src] = 0;
// 	parent[src] = -1;
// 	length[src] = 0;
// }

// void dfs2(int64_t src){
// 	vis[src] = 1;
// 	if(src == N-1){
// 		if(length[src] == store){
// 			cout << store+1 << '\n';
// 			vector<int64_t> ans;
// 			ans.push_back(src);
// 			while(parent[src] != 0){
// 				src = parent[src];
// 				ans.push_back(src);
// 			}
// 			ans.push_back(0);
// 			reverse(ans.begin(), ans.end());
// 			for(auto it : ans){
// 				cout << it+1 << " ";
// 			}
// 			exit(0);
// 		}
// 	}
// 	for(auto it : adj[src]){
// 		if(!vis[it]){
// 			length[it] = length[src] + 1;
// 			parent[it] = src;
// 			dfs2(it);
// 		}
// 	}
// 	vis[src] = 0;
// 	parent[src] = -1;
// 	length[src] = 0;
// }

// int main(){

// 	ios_base::sync_with_stdio(false);cin.tie(NULL); 
// 	#ifndef ONLINE_JUDGE
// 	freopen("E:/CODING/input.txt", "r", stdin); 
// 	freopen("E:/CODING/output.txt", "w", stdout); 
// 	#endif

// 	int64_t i,j,t=1;
// 	// cin>>t;
// 	while(t--){	
// 		 int64_t n,m; cin >> n >> m;
// 		 N = n, M = m;

// 		 for(i=0;i<m;i++){
// 		 	int64_t u,v; cin >> u >> v;
// 		 	adj[u-1].push_back(v-1);
// 		 	// indegree[v-1]++;
// 		 }	

// 		 memset(vis,false,sizeof(vis));
// 		 memset(parent,-1,sizeof(vis));

// 		 dfs(0);
// 		 memset(vis,false,sizeof(vis));
// 		 memset(parent,-1,sizeof(vis));
// 		 for(i=0;i<n;i++){
// 		 	length[i] = 0;
// 		 } 
// 		 dfs2(0);

// 		 cout << "IMPOSSIBLE" << endl;

// 	}
	
//     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
// 	return 0;
// }