#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t a[3005];
int64_t dp[3005][3005];

int64_t go(int64_t curr_left,int64_t curr_right){

	if(curr_left > curr_right)return 0;
	if(dp[curr_left][curr_right]!=-1)return dp[curr_left][curr_right];

	int64_t choice1 = 0,choice2 = 0;
	choice1 = a[curr_left] - go(curr_left+1,curr_right); 
	choice2 = a[curr_right] - go(curr_left,curr_right-1);

	return dp[curr_left][curr_right] = max(choice1,choice2);
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
		int64_t n;cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(0,n-1);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}