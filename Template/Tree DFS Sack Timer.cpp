#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 2e5+5;
vector<int> adj[limit];
bool vis[limit];
int dist[limit];
int starttime[limit];
int endtime[limit];
int timer = 0;

void dfs(int curr, int level = 0){
	vis[curr]=1;
	timer++;
	starttime[curr] = timer;
	dist[curr] = level;
	for(auto v : adj[curr]){
		dfs(v,level+1);
	}
	timer++;
	endtime[curr] = timer;
}

void solve(){
	int i,j;
	int n,q; cin >> n >> q;
	for(i=0;i<n-1;i++){
		int v; cin >> v;
		adj[v-1].push_back(i+1);
	}

	// fill dist,intime,outime
	memset(vis,0,sizeof vis);
	dfs(0);

	// pre computation
	map<int,int> store;
	vector<int> sort_by_start[n];
	
	for(i=0;i<n;i++){
		store[starttime[i]] = i+1;
		sort_by_start[dist[i]].push_back(starttime[i]);
	}
	for(i=0;i<n;i++){
		sort(sort_by_start[i].begin(), sort_by_start[i].end());
	}

	while(q --){
		int x,k; cin >> x >> k;
		x --;
		if(dist[x] < k){
			cout << -1 << '\n';
			continue;
		}
		if(dist[x] == k){
			cout << 1 << '\n';
			continue;
		}
		int idx = lower_bound(sort_by_start[dist[x]-k].begin(),sort_by_start[dist[x]-k].end(),starttime[x]) - sort_by_start[dist[x]-k].begin();
		cout << store[sort_by_start[dist[x]-k][idx-1]] << '\n';
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int64_t t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}