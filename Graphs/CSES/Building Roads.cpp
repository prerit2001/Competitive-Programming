/*
  // BFS
*/


#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5+5; 

vector<int64_t> adj[LIMIT];
bool vis[LIMIT];

void bfs(int64_t src){
	queue<int64_t> q;
	q.push(src);
	while(!q.empty()){
		int64_t curr = q.front();
		q.pop();
		for(auto it : adj[curr]){
			if(!vis[it]){
				vis[it] = true;
				q.push(it);
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
			int64_t u,v; cin >> u >> v;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}

		memset(vis,false,sizeof(vis));
		vector<int64_t> new_roads;
		for(i=0;i<n;i++){
			if(vis[i] == false){
				vis[i] = true;
				bfs(i);
				new_roads.push_back(i);
			}
		}
		int64_t cnt = new_roads.size()-1;
		cout << max(int64_t(0),cnt) << '\n';
		for(i=0;i<new_roads.size()-1;i++){
			cout << new_roads[i]+1 << " " << new_roads[i+1]+1 << '\n';
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}