#include<bits/stdc++.h>
using namespace std;
 
// not working top down TLE coz recursion call stack cannot store 1e8 values so go for bottom up
int64_t go(int64_t curr, int64_t sum, vector<int64_t> dp, vector<int64_t> a, int64_t mod){
	if(curr == sum){
		return 1;
	}
	if(curr > sum){
		return 0;
	}
	if(dp[curr] != -1) return dp[curr];
	int64_t ans = 0;
	for(auto it : a){
		ans += go(curr+it,sum,dp,a,mod);
		ans%=mod;
	}
	return dp[curr] = ans%mod;
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
		int64_t x; cin >> x;
		vector<int64_t> dp(x+1,0);
		vector<int64_t> a(n);
		int64_t mod = 1e9+7;
		for(i=0;i<n;i++){
			int64_t temp; cin >> temp;
			a[i]=temp;
		}
		// dp.resize(x+1,-1);
		// memset(dp, -1, sizeof dp);
		// cout << go(0,x,dp,a,mod)%mod << '\n';
 
		// bottom up
		dp[0] = 1;
		for(i=1;i<=x;i++){
			dp[i] = 0;
			for(auto it : a){
				if(i-it >= 0){
					(dp[i] += dp[i-it]) %= mod;
				}
			}
		}
		cout << dp[x] << '\n';
	}
	
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}