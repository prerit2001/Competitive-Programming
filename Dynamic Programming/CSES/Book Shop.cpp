#include<bits/stdc++.h>
using namespace std;
 
// not working top down go for bottom up, recursion depth too high go for tle
/*int go(int curr, int n, int price, int price_limit){
	if(curr == n){
		if(price <= price_limit) return 0;
		else return -1e7;
	}
	if(price > price_limit) return -1e7;
 
	if(dp[curr][price]!=-1) return dp[curr][price];
 
	int choice1 = s[curr] + go(curr+1,n,price+h[curr],price_limit);
	int choice2 = go(curr+1,n,price,price_limit);
 
	return dp[curr][price] = max(choice1,choice2);
}*/
 
int main(){
 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif
 
	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n; cin >> n;
		int x; cin >> x;
		int h[n];
		int s[n];
		vector<vector<int>> dp(n+1,vector<int>(x+1,0));
 
		for(i=0;i<n;i++) cin >> h[i];
		for(i=0;i<n;i++) cin >> s[i];

		// not working top down go for bottom up, recursion depth too high go for tle
		/*
		function<int(int, int, int, int)> go = [&](int curr, int n, int price, int price_limit) {
     		if(curr == n){
				if(price <= price_limit) return 0;
				else return int(-100000007);
			}
			if(price > price_limit) return int(-100000007);
		 
			if(dp[curr][price]!=-1) return dp[curr][price];
		 
			int choice1 = s[curr] + go(curr+1,n,price+h[curr],price_limit);
			int choice2 = go(curr+1,n,price,price_limit);
		 
			return dp[curr][price] = max(choice1,choice2);
    	};

    	cout << go(0,n,0,x) << '\n';
    	*/

		for(i=1;i<=n;i++){
			for(j=0;j<=x;j++){
				dp[i][j] = dp[i-1][j];
				if(j - h[i-1] >= 0){
					dp[i][j] = max(dp[i][j],dp[i-1][j-h[i-1]]+s[i-1]);
				}
			}
		}

		cout << dp[n][x] << '\n';
		
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}