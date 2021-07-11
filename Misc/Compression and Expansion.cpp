// https://codeforces.com/problemset/problem/1523/C

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i ++){
		int temp; cin >> temp;
		while(v.size() > 0){
			if(v.back() + 1 == temp){
				v.pop_back();
				break;
			}
			if(v.back() >= temp and temp == 1){
				break;
			}
			v.pop_back();
		}
		v.push_back(temp);
		for(int i = 0; i < v.size(); i ++){
			if(i == v.size() - 1){
				cout << v[i] ;
			}
			else{
				cout << v[i] << ".";
			}
		}
		cout << '\n';
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}