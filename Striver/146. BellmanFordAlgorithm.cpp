/*
 	Time O(VE)
 	Space O(V)
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int LIMIT = 25e2 + 5;
vector<tuple<int,int,int>> edge;
int dist[LIMIT] = {};
int parent[LIMIT] = {};

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n,m; cin >> n >> m;

		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			edge.push_back({u-1,v-1,w});
		}	

		for(i=0;i<n;i++){
			dist[i] = 1e15;
		}

		int src = 0;
		dist[src] = 0;

		// bellmen_ford
		for(i=0;i<n-1;i++){
			for(auto [u,v,w] : edge){
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					parent[v] = u;
					// cout << v+1 << " " << u+1 << endl;
				} 
			}
		}

		for(i=0;i<n;i++){
			cout << dist[i] << " ";
		}

		// negative weight cycle
		for(auto [u,v,w] : edge){
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				// cout << v << " ";
				
				// continue;
				cout << "YES\n";
				int curr = v;
				for(i=0;i<n;i++){
					curr = parent[curr];
				}
				v = curr;
				vector<int> path;
				path.push_back(curr);
				while(1){
					curr = parent[curr];
					if(curr == v) break;
					path.push_back(curr);
				}
				path.push_back(v);
				reverse(path.begin(),path.end());
				for(auto it : path){
					cout << it+1 << " ";
				}
				exit(0);
			}
		}

		cout << "NO\n";
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}