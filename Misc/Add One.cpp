#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int dp[200005][10];

int go(int curr, int idx, int maxi, int mod = 1e9 + 7){
	if(idx == maxi)return 0;
	if(dp[maxi - idx][curr] != -1) return dp[maxi - idx][curr];
	int choice = 0;
	if(curr == 9){
		choice = (1%mod + go(0,idx+1,maxi)%mod + go(1,idx+1,maxi)%mod)%mod;
	}
	else{
		choice = (go(curr+1,idx+1,maxi))%mod;
	}
	return dp[maxi - idx][curr] = choice%mod;
}

void solve(){
	int n;
	int m;
	cin >> n >> m;
	int ans = 0, mod = 1e9 + 7;
	while(n > 0){
		ans+=(1%mod+go(n%10,0,m)%mod)%mod;
		ans%=mod;
		n/=10;
	}
	cout << ans << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	memset(dp, -1, sizeof dp);
	while(t--){
		solve();
	}
	
}