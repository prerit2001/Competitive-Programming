#include<bits/stdc++.h>
using namespace std;
 
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
		vector<vector<int>> dp(n+1,vector<int>(x+1,0));
		vector<int64_t> a(n);
		int64_t mod = 1e9+7;
		for(i=0;i<n;i++){
			int64_t temp; cin >> temp;
			a[i]=temp;
		}

		dp[0][0] = 1;
		for(i=1;i<=n;i++){
			for(j=0;j<=x;j++){
				dp[i][j] = dp[i-1][j];
				if(j - a[i-1] >= 0){
					(dp[i][j] += dp[i][j-a[i-1]])%=mod;
				}
			}
		}
		
		cout << dp[n][x] << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}