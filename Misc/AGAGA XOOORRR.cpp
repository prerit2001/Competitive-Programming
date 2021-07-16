#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int a[n];
	map<int,vector<int>> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	int left[n],right[n];
	left[0] = a[0],right[n-1] = a[n-1];
	for(int i = 1; i < n; i ++){
		left[i] = a[i] ^ left[i-1];
		right[n-i-1] = a[n-i-1] ^ right[n-i];
	}
	// all elem equal
	bool eq = 1;
	for(int i = 1; i < n; i ++){
		if(a[i] != a[i-1]) eq = 0;
	}
	if(eq){
		cout << "YES\n";
		return;
	}
	// // exactly 2 elem
	// for(int i = 0; i < n - 1; i ++){
	// 	if(left[i] == right[i+1]){
	// 		cout << "YES\n";
	// 		return;
	// 	}
	// }
	// either
	for(int i = 0; i < n - 1; i ++){
		for(int j = i + 1; j < n; j ++){
			if(left[i] == right[j]){
				if((left[j-1] ^ left[i]) == 0 or (left[j-1] ^ left[i]) == left[i]){
					cout << "YES\n";
					return;
				}
			}
		}
	}

	cout << "NO\n";
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}