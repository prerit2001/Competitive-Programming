// #include<bits/stdc++.h>
// using namespace std;
// #define int int64_t

// const int limit = 2e5+5;
// vector<int> adj[limit];
// bool vis[limit];

// int go(int curr, int taken = 0){
// 	vis[curr] = 1;
// 	int ans = 0;
// 	for(auto v : adj[curr]){
// 		if(!vis[v]){
// 			int choice1 = 0; 
// 			int choice2 = 0;
// 			if(taken == 0){
// 				choice2 = go(v,0);
// 				choice1 = 1 + go(v,1);
// 			}
// 			if(taken == 1){
// 				choice1 = go(v,0);
// 			}
// 			ans = max(choice1,choice2);
// 		}
// 	}
// 	vis[curr] = 0;
// 	return ans;
// }

// pair<int,int> bfs(int curr){
// 	queue<pair<int,int>> q;
// 	q.push({curr,0});
// 	pair<int,int> ans;
// 	vis[curr] = 1;
// 	while(!q.empty()){
// 		auto u = q.front();
// 		q.pop();
// 		ans = u;
// 		for(auto v : adj[u.first]){
// 			if(!vis[v]){
// 				vis[v] = 1;
// 				q.push({v,u.second+1});
// 			}
// 		}
// 	}
// 	return ans;
// }

// void solve(int i = 0, int j = 0){
// 	int n; cin >> n;
// 	for(i=0;i<n-1;i++){
// 		int u,v; cin >> u >> v;
// 		adj[u-1].push_back(v-1);
// 		adj[v-1].push_back(u-1);
// 	}
// 	memset(vis,0, sizeof vis);
// 	auto d1 = bfs(0);
// 	cout << d1.first << endl;
// 	memset(vis,0,sizeof vis);
// 	int ans = go(d1.first);
// 	cout << ans << '\n';
// }

// signed main(){

// 	ios_base::sync_with_stdio(false);cin.tie(NULL);

// 	int t=1;
// 	// cin>>t;
// 	while(t--){
// 		solve();
// 	}
	
// }