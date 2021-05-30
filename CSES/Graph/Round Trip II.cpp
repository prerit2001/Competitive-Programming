/*
 // Detect Cycle in Directed Graph
*/

#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5+5; 

vector<int64_t> adj[LIMIT];

bool done = false;
int64_t point;
int64_t back_step;

void dfs(int64_t src,int64_t vis[],int64_t parent[]){
	vis[src] = 1;
	for(auto it : adj[src]){
		if(!vis[it]){
			parent[it] = src;
			dfs(it,vis,parent);
		}
		else if(vis[it] == 1){
			done = true;
			vector<int64_t> ans;
			ans.push_back(it);
			while(parent[src]!=it){
				ans.push_back(src);
				src = parent[src];
			}
			ans.push_back(src);
			ans.push_back(it);
			reverse(ans.begin(), ans.end());
			vector<int64_t> round_path = ans;
			cout << round_path.size() << '\n';
			for(auto it : round_path){
				cout << it + 1 << " " ;
			}
			cout << '\n';
			exit(0);
		}
	}
	vis[src] = 2;
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
		}

		int64_t vis[n];		
		int64_t parent[n] = {};
		memset(vis,0,sizeof(vis));
		memset(parent,-1,sizeof(parent));

		for(i=0;i<n;i++){
			if(!vis[i] and !done){
				dfs(i,vis,parent);
			}
		}

		if(!done){
			cout << "IMPOSSIBLE\n";
			continue;
		}

	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}