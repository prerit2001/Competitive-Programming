#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 2e5+5;
int64_t a[LIMIT];
int64_t dp[LIMIT];

int64_t go(int64_t curr, int64_t n, int64_t prev){
	if(curr == n){
		return 0;
	}
	
	int64_t choice1 = 0;
	int64_t choice2 = 0;

	if(a[curr] > prev){
		choice1 = 1+go(curr+1,n,curr);
	}
	
	choice2 = go(curr+1,n,0);

	return max(choice1,choice2);
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
			cin >> a[i];
		}
		cout << go(0,n,0);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}