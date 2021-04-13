//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/special-subsequence-2-4c6a2c2b/

#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t a[2001],b[2001];
int64_t dp[2001][2001][2];

int64_t go(int64_t curr_a,int64_t curr_b,int64_t last, int64_t type, int64_t n,int64_t m){
	if(curr_a>=n and type==1)return 0;
	if(curr_b>=m and type==0)return 0;
	if(dp[curr_a][curr_b][type]!=-1)return dp[curr_a][curr_b][type];
	if(type == 1){
		dp[curr_a][curr_b][type]=max(go(curr_a+1,curr_b,last,1,n,m),(a[curr_a]>last?1+go(curr_a+1,curr_b,a[curr_a],0,n,m):int64_t(0)));
		return dp[curr_a][curr_b][type];
	}else{
		dp[curr_a][curr_b][type]=max(go(curr_a,curr_b+1,last,0,n,m),(b[curr_b]>last?1+go(curr_a,curr_b+1,b[curr_b],1,n,m):int64_t(0)));
		return dp[curr_a][curr_b][type];
	}
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	cin>>t;
	while(t--){
		int64_t n,m;cin>>n>>m;
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<m;i++)cin>>b[i];
		memset(dp,-1,sizeof(dp));
		int64_t Start_with_a = go(0,0,-1e8,1,n,m);
		memset(dp,-1,sizeof(dp));
		int64_t Start_with_b = go(0,0,-1e8,0,n,m);
		cout<<max(Start_with_a,Start_with_b)<<'\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}