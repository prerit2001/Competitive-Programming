/*
  // dijtstra algorithm
*/


#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5 + 5;
vector<pair<int64_t,int64_t>> adj[LIMIT],rev_adj[LIMIT];
bool vis_from_1[LIMIT],vis_from_n[LIMIT];
vector<tuple<int64_t,int64_t,int64_t>> edge;
int64_t dist_from_1[LIMIT] = {},dist_from_n[LIMIT] = {};

void dijkstra_from_1(int64_t src){
	priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
	dist_from_1[src - 1] = 0;
	Q.push({src-1,0});
	while(!Q.empty()){
		auto p = Q.top();
		Q.pop();
		if(vis_from_1[p.second]){
			continue;
		}
		vis_from_1[p.second] = 1;
		for(auto &i : adj[p.second]){
			if(!vis_from_1[i.first] and dist_from_1[i.first] > dist_from_1[p.second] + i.second){
				dist_from_1[i.first] = dist_from_1[p.second] + i.second;
				Q.push({dist_from_1[i.first],i.first});
			}
		}
	}
}

void dijkstra_from_n(int64_t src){
	priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
	dist_from_n[src - 1] = 0;
	Q.push({0,src-1});
	while(!Q.empty()){
		auto p = Q.top();
		Q.pop();
		if(vis_from_n[p.second]){
			continue;
		}
		vis_from_n[p.second] = 1;
		for(auto &i : rev_adj[p.second]){
			if(!vis_from_n[i.first] and dist_from_n[i.first] > dist_from_n[p.second] + i.second){
				dist_from_n[i.first] = dist_from_n[p.second] + i.second;
				Q.push({dist_from_n[i.first],i.first});
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
			edge.push_back({u-1,v-1,w});
		}

		for(i=0;i<n;i++){
			dist_from_1[i] = 1e15;
			dist_from_n[i] = 1e15;
		}

		dist_from_1[0] = 0;
		dist_from_n[n-1] = 0;

		memset(vis_from_1,false,sizeof(vis_from_1));
		memset(vis_from_n,false,sizeof(vis_from_n));

		dijkstra_from_1(1);
		dijkstra_from_n(n);

		int64_t ans = 1e18;

		for(auto [u,v,w] : edge){
			if(vis_from_1[u] and vis_from_n[v]){
				ans = min(ans,dist_from_1[u]+dist_from_n[v]+w/2);
			}
		}

		cout << ans << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}