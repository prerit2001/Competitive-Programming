/*
   // modified dijkstra
*/


#include<bits/stdc++.h>
using namespace std;

int64_t N,M;

const int64_t LIMIT = 1e5 + 5;
vector<pair<int64_t,int64_t>> adj[LIMIT];
bool vis[LIMIT];

int64_t dist[LIMIT][15] = {};

void dijkstra_for_K_shortest(int64_t k){
	priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
	Q.push({0,0});
	while(!Q.empty()){
		auto curr = Q.top();
		Q.pop();
		if(dist[curr.second][k-1] < curr.first){
			continue;
		}
		for(auto [v,w] : adj[curr.second]){
			if(dist[v][k-1] > curr.first + w){
				dist[v][k-1] = curr.first + w;
				Q.push({dist[v][k-1],v});
				sort(dist[v],dist[v]+15);
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
		int64_t n,m,k; cin >> n >> m >> k;
		 N = n, M = m;

		 for(i=0;i<m;i++){
		 	int64_t u,v,w; cin >> u >> v >> w;
		 	adj[u-1].push_back({v-1,w});
		 }

		 memset(vis,false,sizeof(vis));
		 for(i=0;i<n;i++){
		 	for(j=0;j<15;j++){
		 		dist[i][j] = 1e15;
		 	}
		 }

		 dijkstra_for_K_shortest(k);
		 for(i=0;i<k;i++){
		 	cout << dist[n-1][i] << " ";
		 }
		 cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}