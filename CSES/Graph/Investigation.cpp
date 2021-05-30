/*
  // dijkstra algo vast
*/

#include<bits/stdc++.h>
using namespace std;

int64_t N,M;

const int64_t LIMIT = 1e5 + 5;
vector<pair<int64_t,int64_t>> adj[LIMIT];
bool vis[LIMIT];
int64_t dist[LIMIT] = {};
int64_t routes[LIMIT] = {};
int64_t min_flight[LIMIT] = {};
int64_t max_flight[LIMIT] = {};

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
				routes[i.first] = routes[p.second];
				min_flight[i.first] = min_flight[p.second]+1;
				max_flight[i.first] = max_flight[p.second]+1;
				Q.push({dist[i.first],i.first});
			}
			else if(!vis[i.first] and dist[i.first] == dist[p.second] + i.second){
				routes[i.first]+=routes[p.second];
				routes[i.first]%=int64_t(1e9+7);
				min_flight[i.first] = min(min_flight[i.first],min_flight[p.second]+1);
				max_flight[i.first] = max(max_flight[i.first],max_flight[p.second]+1);
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
		int64_t n,m; cin >> n >> m;
		N = n, M = m;

		for(i=0;i<m;i++){
			int64_t u,v,w; cin >> u >> v >> w;
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