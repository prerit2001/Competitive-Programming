/*
 // Bellman Ford Algorithm
*/
#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 25e2 + 5;
vector<pair<int64_t,int64_t>> adj[LIMIT],rev_adj[LIMIT];
bool vis_from_1[LIMIT],vis_from_n[LIMIT];
vector<tuple<int64_t,int64_t,int64_t>> edge;
int64_t dist[LIMIT] = {};

void bfs_from_1(int64_t src = 1){	
	queue<int64_t> q;
	q.push(0);
	vis_from_1[0] = 1;
	while(!q.empty()){
		int64_t curr = q.front();
		q.pop();
		for(auto [v,w] : adj[curr]){
			if(!vis_from_1[v]){
				vis_from_1[v] = 1;
				q.push(v);
			}
		}
	}
}

void bfs_from_n(int64_t src){
	queue<int64_t> q;
	q.push(src-1);
	vis_from_n[src-1] = 1;
	while(!q.empty()){
		int64_t curr = q.front();
		q.pop();
		for(auto [v,w] : rev_adj[curr]){
			if(!vis_from_n[v]){
				vis_from_n[v] = 1;
				q.push(v);
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

		for(i=0;i<m;i++){
			int64_t u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
			rev_adj[v-1].push_back({u-1,w});
			edge.push_back({u-1,v-1,-w});
		}	

		memset(vis_from_n,false,sizeof(vis_from_n));
		memset(vis_from_1,false,sizeof(vis_from_1));

		bfs_from_1(1);
		bfs_from_n(n);

		for(i=1;i<n;i++){
			dist[i] = 1e15;
		}

		// bellmen_ford
		for(i=0;i<n-1;i++){
			for(auto [u,v,w] : edge){
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
				} 
			}
		}

		// negative weight cycle
		for(auto [u,v,w] : edge){
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				if(vis_from_1[v] and vis_from_n[v]){
					cout << -1 << '\n';
					exit(0);
				}
			}
		}

		cout << -dist[n-1] << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


/*
 // AC if Graph is DAG : Using Topological Shortest Path Technique

#include<bits/stdc++.h>
using namespace std;

int64_t N,M;

const int64_t LIMIT = 25e2 + 5;
vector<pair<int64_t,int64_t>> adj[LIMIT];
bool vis[LIMIT];

int64_t indegree[LIMIT] = {};
vector<int64_t> topo_sort;

void topological_sort(){
	queue<int64_t> q;
	for(int i=0;i<N;i++){
		if(indegree[i] == 0){
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
			if(--indegree[it.first] == 0){
				q.push(it.first);
			}
		}
	}

	// solution works only in case of DAG
	assert(cnt==N);
}

int64_t dist[LIMIT] = {};

void shortest_path(){
	for(auto u : topo_sort){
		for(auto v : adj[u]){
			dist[v.first] = max(dist[v.first], dist[u] + v.second);
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
		 	indegree[v-1]++;
		 }	

		 memset(vis,false,sizeof(vis));

		 topological_sort();

		 for(i=1;i<n;i++){
		 	dist[i] = -1e15;
 		 }

 		 shortest_path();

 		 if(dist[n-1] == -1e15) cout << -1 << "\n";
 		 else cout << dist[n-1] << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}*/