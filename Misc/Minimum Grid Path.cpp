#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int a[n];
	vector<int> odd,even;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		(i&1) ? odd.push_back(a[i]) : even.push_back(a[i]); 
	}
	int sum = 0;
	int maxi = 1e9+1;
	vector<int> o,e;
	for(int i = 0; i < odd.size(); i ++){
		maxi = min(maxi,odd[i]);
		sum += odd[i];
		o.push_back(sum - maxi + maxi * (n-i));
	}
	sum = 0, maxi = 1e9+1;
	for(int i = 0; i < even.size(); i ++){
		maxi = min(maxi,even[i]);
		sum += even[i];
		e.push_back(sum - maxi + maxi * (n-i));
	}
	int ans = 1e18;
	int ptr1 = 0,ptr2 = 0;
	vector<int> res;
	while(ptr1 < e.size() and ptr2 < o.size()){
		res.push_back(e[ptr1]);
		res.push_back(o[ptr2]);
		ptr1 ++, ptr2 ++;
	}
	if(n&1){
		res.push_back(e[ptr1]);
	}
	for(int i = 1; i < n; i ++){
		ans = min(ans, res[i]+res[i-1]);
	}
	cout << ans << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}