#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 2e5+5;
vector<int64_t> adj[LIMIT];
bool vis[LIMIT] = {};
int64_t dist[LIMIT] = {};
int64_t intime[LIMIT];
int64_t outtime[LIMIT];
int64_t timer = 0;

void bfs(){
	queue<pair<int64_t,int64_t>> q;
	q.push({0,0});
	dist[0] = 0;
	while(!q.empty()){
		auto [u,d] = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(!vis[v]){
				vis[v] = 1;
				q.push({v,d+1});
				dist[v] = d+1;
			}
		}
	}
}

void dfs(int64_t v){
    intime[v] = ++timer;
    vector<int64_t>::iterator it = adj[v].begin();
    while (it != adj[v].end()){
        dfs(*it);
        it++;
    }
    outtime[v] = ++timer;
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
		int64_t n; cin >> n;
		for(i=0;i<n;i++){
			adj[i].clear();
			vis[i]=0;
			dist[i]=LIMIT;
			intime[i]=0;
			outtime[i]=0;
		}
		for(i=2;i<=n;i++){
			int64_t u; cin >> u;
			adj[u-1].push_back(i-1);
		}
		bfs();
		for(i=0;i<n;i++){
			vis[i]=0;
		}
		dfs(0);

		vector<int64_t> res[n];
		for(i=0;i<=n;i++){
			res[dist[i]].push_back(intime[i]); 
		}

		for(i=0;i<n;i++){
			sort(res[i].begin(), res[i].end());
		}

		int64_t q; cin >> q;
		while(q --){
			int64_t u,d; cin >> u >> d;
			int64_t ans = upper_bound(res[d].begin(), res[d].end(),outtime[u-1]) - lower_bound(res[d].begin(), res[d].end(),intime[u-1]);
			cout << ans << '\n';
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}