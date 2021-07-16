#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> v[n-1];
	for(int i = 1; i <= n; i ++){
		int cnt = 0;
		for(int j = i + 1; j <= n; j ++, cnt ++){
			v[cnt].push_back({i,j});
		}
	}
	map<pair<int,int>,int> mp;
	int top = 0, bottom = n - 2;
	while(top < bottom){
		{
			for(int i = 0; i < v[top].size(); i ++){
				mp[{v[top][i].first,v[top][i].second}] = 1;
			}
			for(int i = 0; i < v[bottom].size(); i ++){
				mp[{v[bottom][i].first,v[bottom][i].second}] = -1;
			}
		}
		top ++, bottom --;
	}

	if((top == bottom) and (~n & 1)){
		for(int i = 0; i < v[top].size(); i ++){
			mp[{v[top][i].first,v[top][i].second}] = 0;
		}
		for(int i = 0; i < v[bottom].size(); i ++){
			mp[{v[bottom][i].first,v[bottom][i].second}] = 0;
		}
	}

	for(auto it : mp){
		cout << it.second << " ";
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