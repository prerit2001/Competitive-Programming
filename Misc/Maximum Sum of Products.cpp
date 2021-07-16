#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int a[n],b[n];
	int prod[n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> b[i];
	}
	prod[0] = a[0] * b[0];
	if(n == 1){
		cout << prod[0] << '\n';
		return;
	}
	for(int i = 1; i < n; i ++){
		prod[i] = prod[i-1] + a[i] * b[i];
	}
	int mp[n][n] = {0};
	for(int i = 0; i < n; i ++){
		int left = i - 1, right = i + 1;
		int sum = a[i] * b[i];
		mp[i][i] = sum;
		while(left >= 0 and right < n){
			sum += a[left] * b[right] + a[right] * b[left];
			mp[left][right] = sum;
			left --, right ++;
		}
	}
	for(int i = 0; i < n - 1; i ++){
		int left = i - 1, right = i + 2;
		int sum = a[i] * b[i+1] + a[i+1] * b[i];
		mp[i][i+1] = sum;
		while(left >= 0 and right < n){
			sum += a[left] * b[right] + a[right] * b[left];
			mp[left][right] = sum;
			left --, right ++;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++){
		for(int j = i; j < n; j ++){
			int curr = 0;
			if(i > 0){
				curr += prod[i-1];
			}
			curr += mp[i][j];
			if(j < n - 1){
				curr += prod[n-1] - prod[j]; 
			}
			ans = max(curr,ans);
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