#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 5e2+5;
int64_t dp[LIMIT][LIMIT];

int64_t go(int64_t n, int64_t m){
	if(n == m)	return 0;
	if(dp[n][m]!=-1) return dp[n][m];

	int64_t ans = 1e7;
	for(int64_t i=1;i<n;i++){
		ans = min(ans, 1+go(n-i,m)+go(i,m));
	}
	for(int64_t i=1;i<m;i++){
		ans = min(ans, 1+go(n,m-i)+go(n,i));
	}

	return dp[n][m] = ans;
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
		int64_t m; cin >> m;
		memset(dp, -1, sizeof dp);
		cout << go(n,m) ;
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}