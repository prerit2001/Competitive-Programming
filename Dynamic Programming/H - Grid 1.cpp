#include<bits/stdc++.h>
using namespace std;

int i,j;
string s[1005];
int64_t ans = 0;
int64_t dp[1005][1005];
int64_t mod = 1e9+7;

int64_t go(int64_t curr_i,int64_t curr_j,int64_t H,int64_t W){
	if(curr_i>H or curr_j>W)return 0;
	if(s[curr_i-1][curr_j-1] == '#')return 0;
	if(curr_i==H and curr_j==W){
		return 1;
	}
	if(dp[curr_i][curr_j]!=-1){
		return dp[curr_i][curr_j]%mod;
	}
	int64_t choice1 = 0, choice2 = 0;
	if(curr_i + 1 <= H){
		choice1 = go(curr_i+1,curr_j,H,W);
	}
	if(curr_j + 1 <= W){
		choice2 = go(curr_i,curr_j+1,H,W);
	}
	return dp[curr_i][curr_j] = (choice1%mod+choice2%mod)%mod;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	// cin>>t;
	while(t--){
		int64_t h,w;
		cin>>h>>w;
		for(i=0;i<h;i++){
			cin>>s[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(1,1,h,w);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}