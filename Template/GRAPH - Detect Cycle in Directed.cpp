/*
 // Detect Cycle in Directed Graph :- CSES ROUND TRIP 2
*/

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int LIMIT = 1e5+5; 

vector<int> adj[LIMIT];

bool done = false;
int point;
int back_step;

void dfs(int src,int vis[],int parent[]){
	vis[src] = 1;
	for(auto it : adj[src]){
		if(!vis[it]){
			parent[it] = src;
			dfs(it,vis,parent);
		}
		else if(vis[it] == 1){
			done = true;
			vector<int> ans;
			ans.push_back(it);
			while(parent[src]!=it){
				ans.push_back(src);
				src = parent[src];
			}
			ans.push_back(src);
			ans.push_back(it);
			reverse(ans.begin(), ans.end());
			vector<int> round_path = ans;
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

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n,m; cin >> n >> m;

		for(i=0;i<m;i++){
			int u,v; cin >> u >> v;
			adj[u-1].push_back(v-1);
		}

		int vis[n];		
		int parent[n] = {};
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