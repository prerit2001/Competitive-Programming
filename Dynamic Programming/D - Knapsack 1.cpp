#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t w[105],v[105];
int64_t dp[105][100005];

int64_t go(int64_t curr,int64_t W,int64_t limit,int64_t n){
	if(dp[curr][W]!=-1)return dp[curr][W];
	if(curr >= n){
		return 0;
	}
	int64_t choice1 = 0, choice2 = 0;
	if(W + w[curr] <= limit){
		choice1 = v[curr]+go(curr+1,W+w[curr],limit,n);
	}
	if(W <= limit){
		choice2 = go(curr+1,W,limit,n);
	}
	return dp[curr][W] = max(choice1,choice2);
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
		int64_t n,W;cin>>n>>W;
		for(i=0;i<n;i++){
			cin>>w[i]>>v[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(0,0,W,n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}