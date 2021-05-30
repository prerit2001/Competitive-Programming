#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e5+5;
int64_t a[LIMIT];
int64_t N;
int64_t mod = 1e9+7;
int64_t store = 0;
int64_t dp[LIMIT][105];

int64_t go(int64_t start, int64_t end, int64_t prev, int64_t m){
	if(start > end){
		if(end == N-1){
			return 1;
		}
		else if(prev <= a[end+1]+1 and prev >= a[end+1]-1 and prev >= 1 and prev <= m){
			return 1;
		}
		else return 0;
	}
	if(dp[start][prev]!=-1){
		return dp[start][prev];
	}
	int64_t ans = 0;
	if(start == 0){
		// all m are considered
		for(int64_t i=1;i<=m;i++){
			ans += go(start+1,end,i,m);
			ans%=mod;
		}
	}
	else{
		if(a[start-1] != 0){
			// max 3 choices only
			for(int64_t i=max(a[start-1]-1,int64_t(1));i<=min(a[start-1]+1,m);i++){
				ans += go(start+1,end,i,m);
				ans%=mod;
			}
		}
		else{
			// max 3 choices only
			for(int64_t i=max(prev-1,int64_t(1));i<=min(prev+1,m);i++){
				ans += go(start+1,end,i,m);
				ans%=mod;
			}
		}
	}

	return dp[start][prev]= ans%mod;
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
		int64_t m; cin >> m;
		N = n;
		memset(dp, -1, sizeof dp);
		for(i=0;i<n;i++){
			cin >> a[i];
		}
		
		int64_t prod = 1;
		
		bool ok = 1;
		for(i=1;i<n;i++){
			if(a[i]!=0 and a[i-1]!=0){
				if(abs(a[i]-a[i-1]) > 1) ok = 0; 
			}
		}

		if(!ok){
			cout << 0 << '\n';
			continue;
		}

		for(i=0;i<n;i++){
			if(a[i] == 0){
				int64_t start = i;
				while(i < n and a[i] == 0){
					i ++;
				}
				i--;
				int64_t end = i;
				store = start;
				prod=prod%mod*go(start,end,104,m)%mod;
				prod%=mod;
			}
		}
		cout << prod%mod << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}