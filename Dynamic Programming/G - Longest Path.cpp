#include<bits/stdc++.h>
using namespace std;

int i,j;
vector<int64_t> adj[100005];
int64_t dp[100005];

int64_t go(int64_t curr){
	if(dp[curr] != -1)return dp[curr];
	if(adj[curr].size() == 0)return 0;
	int64_t choice = 0;
	for(int64_t i = 0;i < adj[curr].size();i++){
		choice = max(choice,1+go(adj[curr][i]));
	}
	return dp[curr] = choice;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	// cin>>t;
	while(t--){
		int64_t n,m;cin>>n>>m;
		for(i=0;i<m;i++){
			int64_t u,v;
			cin>>u>>v;
			adj[u-1].push_back(v-1);
		}
		memset(dp,-1,sizeof(dp));
		int64_t maxi = 0;
		for(i=0;i<n;i++){
			maxi = max(maxi,go(i));
		}
		cout<<maxi;
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}