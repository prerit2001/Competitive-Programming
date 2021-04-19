#include<bits/stdc++.h>
using namespace std;


int64_t a[105];
int64_t dp[105][100005];
int64_t mod = 1e9+7;

int64_t go(int64_t curr,int64_t sum,int64_t n,int64_t k){

	if(curr >= n){
		return sum == k ? 1 : 0;
	}
	if(dp[curr][sum]!=-1)return dp[curr][sum]%mod;

	int64_t choice = 0;
	int64_t ans = 0;
	for(int i=0;i<=a[curr];i++){
		choice = (choice%mod+go(curr+1,sum+i,n,k)%mod)%mod;
	}
	
	return dp[curr][sum] = choice%mod;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	int i,j;
	// cin>>t;
	while(t--){
		int64_t n,k;cin>>n>>k;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(0,0,n,k);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}