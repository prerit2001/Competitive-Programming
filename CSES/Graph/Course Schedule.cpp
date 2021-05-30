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
			if(--indegree[it] == 0){
				q.push(it);
			}
		}
	}

	// Graph has Cycle
	if(cnt != N){
		cout << "IMPOSSIBLE\n";
		exit(0);
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

		 topological_sort();

		 for(auto it : topo_sort){
		 	cout << it+1 << " ";
		 }
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}