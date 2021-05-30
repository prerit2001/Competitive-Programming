#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e6+5;
int64_t dp[LIMIT];
int64_t mod = 1e9+7;

int64_t go(int64_t curr, int64_t n){
	if(curr == n) return 1;
	if(curr > n) return 0;
	if(dp[curr]!=-1) return dp[curr];
	int64_t ans = 0;
	for(int i=1;i<=6;i++){
		(ans += go(curr+i,n)) %= mod;
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
		memset(dp, -1, sizeof dp);
		cout << go(0,n) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}