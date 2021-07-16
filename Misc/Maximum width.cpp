#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n,m; cin >> n >> m;
	int suff[m] = {},pref[m] = {};
	string s,t; cin >> s >> t;
	int last = m - 1;
	int idx = n - 1;
	while(last >= 0){
		while(s[idx] != t[last]){
			idx --;
			assert(idx >= 0);
		}
		suff[last] = idx;
		idx --;
		last --;
	}
	last = 0, idx = 0;
	while(last < m){
		while(s[idx] != t[last]){
			idx ++;
			assert(idx < n);
		}
		pref[last] = idx;
		idx ++;
		last ++; 
	}


	
	int ans = suff[1] - pref[0]; 
	for(int i = 2; i < m; i ++){
		ans = max(suff[i] - pref[i-1],ans);
	}
	cout << ans << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}