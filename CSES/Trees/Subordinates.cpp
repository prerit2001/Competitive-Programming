#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int limit = 2e5+5;
vector<int> adj[limit];
bool vis[limit];
int timer = 0;
int start_time[limit],end_time[limit];

void dfs(int curr){
	timer++;
	vis[curr]=1;
	start_time[curr] = timer;
	for(auto v : adj[curr]){
		dfs(v);
	}
	timer ++;
	end_time[curr] = timer;
}

void solve(){
	int i,j;
	int n; cin >> n;
	int a[n];
	for(i=0;i<n-1;i++){
		cin >> a[i];
		adj[a[i]-1].push_back(i+1);
	}
	memset(vis,0,sizeof vis);
	memset(start_time,0,sizeof start_time);
	memset(end_time,0,sizeof end_time);
	dfs(0);
	for(i=0;i<n;i++){
		cout << (end_time[i]-start_time[i])/2 << " " ;
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