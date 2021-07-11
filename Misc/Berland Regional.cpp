// https://codeforces.com/contest/1519/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int u[n],s[n];
	map<int,vector<int>> mp;
	for(int i = 0; i < n; i ++){
		cin >> u[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> s[i];
		mp[u[i]].push_back(s[i]);
	}
	int ans[n+1] = {};
	for(auto [ui,v] : mp){
		sort(v.begin(), v.end());
		vector<int> pre;
		pre = v;
		for(int i = 1; i < v.size(); i ++){
			pre[i] += pre[i-1];
		}
		for(int i = 1; i <= v.size(); i ++){
			int rem = v.size() % i;
			int to_add = pre.back();
			if(rem > 0){
				to_add -= pre[rem - 1];
			}
			ans[i] += to_add;
		}
	}
	for(int i = 1; i <= n; i ++){
		cout << ans[i] << " ";
	}
	cout << '\n';

}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}