/*
  // bfs with path
*/

#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5+5; 

vector<int64_t> adj[LIMIT];
bool vis[LIMIT];

int64_t parent[LIMIT] = {};

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
				parent[it] = curr;
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

		vis[0] = true;
		bfs(0);
		if(vis[n-1] == false){
			cout << "IMPOSSIBLE\n";
			continue;
		}

		vector<int64_t> path;
		int64_t last = n-1;
		path.push_back(last);
		while(1){
			int64_t curr = last;
			int64_t parent_curr = parent[curr];
			if(curr == 0)break;
			path.push_back(parent_curr);
			last = parent_curr;
		}
		
		reverse(path.begin(),path.end());
		cout << path.size() << '\n';
		for(auto it : path){
			cout << it + 1 << " " ;
		}
		cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}