#include<bits/stdc++.h>
using namespace std;

string s;
int64_t dp[20][200][2] = {};

int64_t go(int64_t n, int64_t sum, int64_t tight = 1){
	if(n == 0){
		if(sum == 0) return 1;
		else return 0;
	}
	if(dp[n][sum][tight]!=-1)return dp[n][sum][tight];
	int64_t ans = 0;
	int64_t upper_bound = 9;
	if(tight == 1){
		upper_bound = s[s.size() - n] - '0';
	}
	for(int64_t i=0;i<=upper_bound;i++){
		ans += go(n-1,sum-i,(tight&(i==upper_bound)));
	}
	return dp[n][sum][tight] = ans;
}

void brute(int64_t n, int64_t sum){
	int64_t ans = 0;
	for(int64_t i=0;i<=599;i++){
		int64_t temp = i;
		int64_t s = 0;
		while(temp){
			s+=temp%10;
			temp/=10;
		}
		if(s == sum) ans++;
	}
	cout << "brute force : " << ans << endl;
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
		s = "599";
		int64_t sum = 6;
		memset(dp,-1,sizeof dp);
		int64_t left = go(s.size(),sum);
		cout << "dp : " << left << endl;
		brute(s.size(),sum);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}