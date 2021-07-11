// https://codeforces.com/problemset/problem/1535/C

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	string s; cin >> s;
	int n = s.size();

	int fn = -1;
	for(int i = 0; i < n; i ++){
		if(s[i] != '?'){
			fn = i;
			break;
		}
	}
	if(fn == -1){
		cout << n * (n+1) / 2 << endl;
		return;
	}


	int ans = 0;
	int dp[n+1][2];
	dp[0][0] = 0, dp[0][1] = 0;

	for(int i = 0; i < n; i ++){
		if(s[i] == '?'){
			dp[i+1][0] = 1 + dp[i][1];
			dp[i+1][1] = 1 + dp[i][0];
		}
		if(s[i] == '0'){
			dp[i+1][0] = 1 + dp[i][1];
			dp[i+1][1] = 0;
		}
		if(s[i] == '1'){
			dp[i+1][1] = 1 + dp[i][0];
			dp[i+1][0] = 0;
		}
		// cout << dp[i+1][0] << " " << dp[i+1][1] << endl;
		ans += max(dp[i+1][0],dp[i+1][1]);
	}

	cout << ans << endl;

}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}