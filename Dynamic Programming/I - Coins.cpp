#include<bits/stdc++.h>
using namespace std;

int i,j;
long double a[3005];
long double dp[3005][3005];

long double go(int64_t curr,int64_t head,int64_t tail,int64_t n){
	if(curr == n and head > tail){
		return 1;
	}
	if(curr == n){
		return 0;
	}
	if(dp[curr][head]!=-1.0){
		return dp[curr][head];
	}

	long double choice1 = 0, choice2 = 0;
	choice1 = a[curr] * go(curr+1,head+1,tail,n);
	choice2 = (1-a[curr]) * go(curr+1,head,tail+1,n);

	return dp[curr][head] = choice1 + choice2;
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
		for(i=0;i<3005;i++){
			for(j=0;j<3005;j++){
				dp[i][j] = -1.0;
			}
		}
		cout<<setprecision(9)<<fixed<<go(0,0,0,n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}