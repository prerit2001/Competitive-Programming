#include<bits/stdc++.h>
using namespace std;

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
		int64_t a[n];
		for(i=0;i<n;i++){
			cin >> a[i];
		}
		bitset<100005> dp[105];
		
		dp[0][0] = 1;
		for(i=1;i<=n;i++){
			for(j=0;j<=100005;j++){
				if(dp[i-1][j] == 1){
					dp[i][j] = 1;
				}
				else{
					if(j-a[i-1] >= 0 and dp[i-1][j-a[i-1]] == 1){
						dp[i][j] = 1;
					}
				}
			}
		}

		set<int64_t> s;

		for(i=1;i<=100005;i++){
			if(dp[n][i] == 1)  s.insert(i);
		}

		cout << s.size() << '\n';
		for(auto it : s){
			cout << it << " ";
		}

	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}