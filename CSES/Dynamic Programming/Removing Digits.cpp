#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e6;
int64_t dp[LIMIT];

int64_t go(int64_t n){
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return 1e7;
	}
	if(dp[n]!=-1)return dp[n];
	int64_t ans = 1e10;
	int64_t temp = n;
	while(temp){
		if(temp%10!=0){
			ans = min(ans,1+go(n-temp%10));
		}
		temp/=10;
	}
	return dp[n] = ans;
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
		memset(dp,-1,sizeof dp);
		cout << go(n) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}