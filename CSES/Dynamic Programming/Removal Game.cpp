#include<bits/stdc++.h>
using namespace std;

const int LIMIT = 5e3+5;
int64_t dp[LIMIT][LIMIT];
int64_t a[LIMIT];

int64_t go(int left,int right){
	if(left > right) return 0;
	if(left == right) return a[left];
	if(dp[left][right]!=-1) return dp[left][right];
	int64_t choice1 = a[left] + min(go(left+1,right-1),go(left+2,right));
	int64_t choice2 = a[right] + min(go(left+1,right-1),go(left,right-2));
	return dp[left][right] = max(choice1,choice2);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	{
		int n; cin >> n;
		int64_t sum = 0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum += a[i];
		}
		memset(dp, -1, sizeof dp);
		cout << go(0,n-1) ;
	}
}