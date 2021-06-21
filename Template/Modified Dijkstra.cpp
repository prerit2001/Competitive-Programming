/*
  // dijkstra algo vast
*/

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int N,M;

const int LIMIT = 1e5 + 5;
vector<pair<int,int>> adj[LIMIT];
bool vis[LIMIT];
int dist[LIMIT] = {};
int routes[LIMIT] = {};
int min_flight[LIMIT] = {};
int max_flight[LIMIT] = {};

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
				routes[i.first] = routes[p.second];
				min_flight[i.first] = min_flight[p.second]+1;
				max_flight[i.first] = max_flight[p.second]+1;
				Q.push({dist[i.first],i.first});
			}
			else if(!vis[i.first] and dist[i.first] == dist[p.second] + i.second){
				routes[i.first]+=routes[p.second];
				routes[i.first]%=int(1e9+7);
				min_flight[i.first] = min(min_flight[i.first],min_flight[p.second]+1);
				max_flight[i.first] = max(max_flight[i.first],max_flight[p.second]+1);
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
		int n,m; cin >> n >> m;
		N = n, M = m;

		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
		}

		memset(vis,false,sizeof(vis));
		for(i=0;i<n;i++){
			dist[i] = 1e15;
		}
		routes[0] = 1;
		min_flight[0] = 0;
		max_flight[0] = 0;

		dijkstra();

		cout << dist[n-1] << " ";
		cout << routes[n-1] << " ";
		cout << min_flight[n-1] << " ";
		cout << max_flight[n-1] << " ";
	}
	
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}