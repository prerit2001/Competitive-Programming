// https://codeforces.com/contest/1515/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int m,x; cin >> m >> x;
	int a[n];
	vector<pair<int,int>> v;
	for(int i = 0; i < n; i ++){
		int temp; cin >> temp;
		v.push_back({temp,i});
		a[i] = temp;
	}
	sort(v.begin(), v.end(),greater<pair<int,int>>());
	int ans[n];
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		ans[v[i].second] = (cnt++) % m;
	}
	int check[m] = {};
	for(int i = 0; i < n; i ++){
		check[ans[i]] += a[i];
	}
	sort(check,check+m);
	if(check[m-1] - check[0] > x){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 0; i < n; i ++){
		cout << ans[i]+1 << " ";
	}
	cout << "\n";
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}