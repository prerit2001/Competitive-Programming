/*
   // dijkstra algo
*/

#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5 + 5;

vector<pair<int64_t,int64_t>> adj[LIMIT];
int64_t dist[LIMIT];
int64_t vis[LIMIT];

void dijkstra(){
	priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
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

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n, m; cin >> n >> m;
		for(i=0;i<m;i++){
			int64_t u,v,w; cin >> u >> v >> w;
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

const int64_t LIMIT = 1e5 + 5;
int64_t N,M;
map<pair<int64_t,int64_t>,int64_t> edge;
set<pair<int64_t,int64_t>> adj[LIMIT];
int64_t dist[LIMIT];
bool vis[LIMIT];
 
void dijkstra(){
	set<pair<int64_t,int64_t>> pq;
	pq.insert({0,0});
	while(!pq.empty()){
		auto u = pq.begin();
		int64_t min_index = u->second;
		pq.erase(pq.begin());

		if(vis[min_index]) continue;

		vis[min_index] = true;
		vector<pair<int64_t,int64_t>> del;
		for(auto it : adj[min_index]){
			if(vis[it.first]){
				del.push_back(it);
			}
		}
		for(auto it : del){
			adj[min_index].erase(it);
		}
		for(auto itt : adj[min_index]){
			int64_t it = itt.first;
			if(dist[it] > (dist[min_index] + edge[{min_index,it}])){
				dist[it] = (dist[min_index] + edge[{min_index,it}]);
				pq.insert({dist[it],it});
			}
		}
	}
}
*/