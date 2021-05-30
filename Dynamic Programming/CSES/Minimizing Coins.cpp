#include<bits/stdc++.h>
using namespace std;

// int64_t dp[1000006];
// set<int64_t> a;
// int64_t mod = 1e9+7;

// TLE in top down go for bottom up
/*int64_t go(int64_t curr, int64_t sum){
	if(curr == sum){
		return 0;
	}
	if(curr > sum){
		return 1e7;
	}
	if(dp[curr] != -1) return dp[curr];
	int64_t ans = 1e7;
	for(auto it : a){
		ans = min(1 + go(curr+it,sum),ans);
		ans %= mod;
	}
	return dp[curr] = ans%mod;
}
*/
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
		int64_t dp[x+1];
		set<int64_t> a;
		int64_t mod = 1e9+7;
		for(i=0;i<n;i++){
			int64_t temp; cin >> temp;
			a.insert(temp);
		}
		memset(dp, -1, sizeof dp);
		// int64_t ans = go(0,x)%mod;

		dp[0] = 0;
		for(i=1;i<=x;i++){
			dp[i] = 1e7;
			for(auto it : a){
				if(i - it >= 0){
					( dp[i] = min(dp[i],dp[i-it]+1) ) %= mod ;
				}
			}
		}

		int64_t ans = dp[x];
		cout << (ans > 1e6 ? -1 : ans) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}