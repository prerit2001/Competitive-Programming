#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t a[100005],b[100005],c[100005];
int64_t dp[100005][3] = {};

int64_t go(int64_t curr,int64_t n,char prev){

	if(curr!=0 and dp[curr][prev-'a'] != -1)return dp[curr][prev-'a'];
	if(curr >= n){
		return 0;
	}

	if(curr == 0){
		int64_t choice1 = 0,choice2 = 0,choice3 = 0;
		choice1 = a[curr]+go(curr+1,n,'a');
		choice2 = b[curr]+go(curr+1,n,'b');
		choice3 = c[curr]+go(curr+1,n,'c');
		return dp[curr][prev-'a'] = max({choice1,choice2,choice3});
	}
	else{
		if(prev == 'a'){
			int64_t choice1 = 0,choice2 = 0;
			choice1 = b[curr]+go(curr+1,n,'b');
			choice2 = c[curr]+go(curr+1,n,'c');
			return dp[curr][prev-'a'] = max(choice1,choice2);
		}
		else if(prev == 'b'){
			int64_t choice1 = 0,choice2 = 0;
			choice1 = a[curr]+go(curr+1,n,'a');
			choice2 = c[curr]+go(curr+1,n,'c');
			return dp[curr][prev-'a'] = max(choice1,choice2);
		}
		else{
			int64_t choice1 = 0,choice2 = 0;
			choice1 = a[curr]+go(curr+1,n,'a');
			choice2 = b[curr]+go(curr+1,n,'b');
			return dp[curr][prev-'a'] = max(choice1,choice2);
		}
	}
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
			cin>>a[i]>>b[i]>>c[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<go(0,n,'z');
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}