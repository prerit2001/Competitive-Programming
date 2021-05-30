// https://cses.fi/problemset/task/2220/

#include<bits/stdc++.h>
using namespace std;

string s;
int64_t dp[20][256][2][2] = {};

int64_t go(int64_t n, char prev, int64_t tight = 1, int64_t leading_zero = 0){
	if(n == 0){
		return 1;	
	}
	if(dp[n][prev][tight][leading_zero]!=-1)return dp[n][prev][tight][leading_zero];
	int64_t ans = 0;
	int64_t upper_bound = 9;
	if(tight == 1){
		upper_bound = s[s.size()-n] - '0';
	}
	for(int64_t i=0;i<=upper_bound;i++){
		if(char(i+'0') != prev or leading_zero == 0){
			ans += go(n-1,char(i+'0'),tight&i==upper_bound, leading_zero||i!=0);
		}
	}
	return dp[n][prev][tight][leading_zero] = ans;
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
		string l,r; cin >> l >> r;
		s = l;
		memset(dp, -1, sizeof dp);
		int64_t left = go(s.size(),'a');
		// cout << left << endl;
		s = r;
		memset(dp, -1, sizeof dp);
		int64_t right = go(s.size(),'a');
		// cout << right << endl;

		bool ok = 1;
		for(i=1;i<l.size();i++){
			if(l[i]==l[i-1])ok = 0;
		}

		cout << right - left + ok << endl;
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}