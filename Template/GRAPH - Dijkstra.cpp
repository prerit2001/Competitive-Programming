/*
   // dijkstra algo
*/

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int LIMIT = 1e5 + 5;

vector<pair<int,int>> adj[LIMIT];
int dist[LIMIT];
int vis[LIMIT];

void dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	dist[0] = 0;
	Q.push({0,0});
	while(!Q.empty()){
		auto p = Q.top();
		Q.pop();
		if(vis[p.second]){
			continue;
		}
		vis[p.second] = 1;
		for(auto &i : adj[p.second]){
			if(!vis[i.first] and dist[i.first] > dist[p.second] + i.second){
				dist[i.first] = dist[p.second] + i.second;
				Q.push({dist[i.first],i.first});
			}
		}
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n, m; cin >> n >> m;
		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
		}
		memset(vis,0,sizeof(vis));
		for(i=1;i<n;i++){
			dist[i] = 1e15;
		}
		dijkstra();
		for(i=0;i<n;i++){
			cout << dist[i] << " ";
		}
		cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

/* 
Aither Solution
const int LIMIT = 1e5 + 5;
int N,M;
map<pair<int,int>,int> edge;
set<pair<int,int>> adj[LIMIT];
int dist[LIMIT];
bool vis[LIMIT];
 
void dijkstra(){
	set<pair<int,int>> pq;
	pq.insert({0,0});
	while(!pq.empty()){
		auto u = pq.begin();
		int min_index = u->second;
		pq.erase(pq.begin());
		if(vis[min_index]) continue;
		vis[min_index] = true;
		vector<pair<int,int>> del;
		for(auto it : adj[min_index]){
			if(vis[it.first]){
				del.push_back(it);
			}
		}
		for(auto it : del){
			adj[min_index].erase(it);
		}
		for(auto itt : adj[min_index]){
			int it = itt.first;
			if(dist[it] > (dist[min_index] + edge[{min_index,it}])){
				dist[it] = (dist[min_index] + edge[{min_index,it}]);
				pq.insert({dist[it],it});
			}
		}
	}
}
*/