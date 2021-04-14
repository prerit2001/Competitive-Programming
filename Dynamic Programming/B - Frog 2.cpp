#include<bits/stdc++.h>
using namespace std;

int64_t h[100005] = {};
int64_t dp[100005] = {};

int64_t go(int64_t curr,int64_t n,int64_t k){
	if(dp[curr]!=-1)return dp[curr];
	if(curr == n-1)return 0;
	if(curr >= n)return 1e10;
	int64_t choice = LLONG_MAX;
	for(int i=curr+1;i<=curr+k and i<n;i++){
		choice = min(choice,abs(h[i]-h[curr])+go(i,n,k));
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
	int i,j;
	while(t--){
		int64_t n,k;cin>>n>>k;
		int64_t a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
			h[i]=a[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(0,n,k);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}