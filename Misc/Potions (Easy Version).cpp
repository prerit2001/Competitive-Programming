// https://codeforces.com/contest/1526/problem/C1

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int a[n];
	bool pos = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		pos |= a[i] >= 0;
	}
	if(!pos){
		cout << "0\n";
		return;
	}

	int dp[n+1][n+1];
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= n; j ++){
			dp[i][j] = -2e13;
		}
	}

	int ans = 1;
	dp[0][0] = 0, dp[0][1] = a[0];
	for(int i = 1; i < n; i ++){
		dp[i][0] = 0;
		for(int j = 1; j <= i + 1; j ++){
			if(dp[i-1][j-1] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[i]);
				if(dp[i][j] >= 0)ans = max(ans, j);
			}
			if(dp[i-1][j-1] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
				if(dp[i][j] >= 0)ans = max(ans, j);
			}
			
		}
	}


	// for(int i = 0; i < n; i ++){
	// 	for(int j = 0; j <= n; j ++){
	// 		if(dp[i][j] > -1e9)
	// 		cout << dp[i][j] << " ";
	// 		else
	// 		cout << "? ";
	// 	}
	// 	cout << endl;
	// }


	cout << ans << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}