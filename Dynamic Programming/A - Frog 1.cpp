#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t h[100005] = {};
int64_t dp[100005] = {};

int64_t go(int64_t curr,int64_t n){
	if(dp[curr]!=-1)return dp[curr];
	if(curr == n-1){
		return 0;
	}
	if(curr >= n){
		return 1e10;
	}
	int64_t choice1 = LLONG_MAX,choice2 = LLONG_MAX;
	if(curr + 1 < n){
		choice1 = abs(h[curr+1]-h[curr])+go(curr+1,n);
	}
	if(curr + 2 < n){
		choice2 = abs(h[curr+2]-h[curr])+go(curr+2,n);
	}
	return dp[curr] = min(choice1,choice2);
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
		int64_t n;cin>>n;
		int64_t a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
			h[i]=a[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(0,n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}