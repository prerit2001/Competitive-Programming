/*
   // Modified bfs
*/


#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5+5;

vector<int64_t> adj[LIMIT];
bool vis[LIMIT];

int64_t ans[LIMIT] = {};
int64_t flag = 1;

void bfs(int64_t curr){
	vis[curr] = true;
	ans[curr] = 1;
	queue<int64_t> q;
	q.push(curr);
	while(!q.empty()){
		curr = q.front();
		q.pop();
		for(auto it : adj[curr]){
			if(vis[it]){
				if(ans[it]==ans[curr]){
					flag = 0;
				}
			}
			else{
				vis[it] = true;
				q.push(it);
				ans[curr] == 1 ? ans[it] = 2 : ans[it] = 1;
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

		for(i=0;i<n;i++){
			if(!vis[i]){
				bfs(i);
			}
		}	

		if(!flag){
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for(i=0;i<n;i++){
			cout << ans[i] << " " ;
		}
		cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}