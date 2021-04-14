#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t w[105],v[105];
int64_t dp[105][100005];
set<pair<int64_t,int64_t>> s;

int64_t go(int64_t curr,int64_t V,int64_t limit,int64_t n){

	if(V>limit)return 1e10;
	if(curr >= n and V == limit)return 0;
	if(curr >= n)return 1e10;
	if(dp[curr][limit-V] != -1){;
		return dp[curr][limit-V];
	}

	int64_t choice1 = LLONG_MAX;
	int64_t choice2 = LLONG_MAX;
	if(V <= limit){
		choice1 = go(curr+1,V,limit,n);
	}
	if(V+v[curr] <= limit){
		choice2 = w[curr]+go(curr+1,V+v[curr],limit,n);
	}
	// cout<<curr<<" "<<V<<endl;
	return dp[curr][limit-V] = min(choice1,choice2);

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
		int64_t n,W;cin>>n>>W;
		int64_t ans = 0;
		for(i=0;i<n;i++){
			cin>>w[i]>>v[i];
			ans+=v[i];
		}
		memset(dp,-1,sizeof(dp));
		int64_t cnt = 0;
		for(i=ans;i>=0;i--){
			if(go(0,0,i,n)<=W){
				cout<<i<<endl;
				break;
			}

		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}