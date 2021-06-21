#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e3+5;
string s[LIMIT];
int64_t dp[LIMIT][LIMIT];
int64_t mod = 1e9+7;

int64_t go(int64_t curr_x, int64_t curr_y, int64_t n){
	if(s[curr_x][curr_y] == '*') return 0;
	if(curr_x == n-1 and curr_y == n-1) return 1;
	if(curr_x == n or curr_y == n) return 0;

	if(dp[curr_x][curr_y]!=-1) return dp[curr_x][curr_y]%mod;

	int64_t choice1 = go(curr_x+1,curr_y,n);
	int64_t choice2 = go(curr_x,curr_y+1,n);

	return ( dp[curr_x][curr_y] = choice1%mod + choice2%mod ) %= mod;
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
		for(i=0;i<n;i++){
			cin >> s[i];
		}
		memset(dp, -1, sizeof dp);
		cout << go(0,0,n) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}