#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int a[n],b[n],c[n];
	for(int i = 0; i < n; i ++) cin >> c[i];
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	int ans = 0;
	int res = abs(a[1] - b[1]);
	for(int i = 1; i < n; i ++){
		if(i == n - 1){
			ans = max(ans, res + 2 + c[i] - 1);
		}
		else if(a[i+1] == b[i+1]){
			ans = max(ans, res + 2 + c[i] - 1);
			res = 0;
		}
		else{
			ans = max(ans, res + 2 + c[i] - 1);
			res += 2 + c[i] - abs(a[i+1] - b[i+1]) - 1;
		}
	}
	res = c[n-1] - 1;
	for(int i = n - 1; i >= 1; i --){
		if(i == 1){
			ans = max(ans, res + 2 + abs(a[i] - b[i]));
		}
		else if(a[i] == b[i]){
			ans = max(ans, res + 2);
			res = c[i-1] - 1;
		}
		else{
			ans = max(ans, res + 2 + abs(a[i] - b[i]));
			res += 2 + c[i-1] - abs(a[i] - b[i]) - 1; 
		}
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