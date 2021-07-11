// https://codeforces.com/contest/1526/problem/C2

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int a[n];
	bool pos = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		pos |= a[i] >= 0;
	}
	if(!pos){
		cout << "0\n";
		return;
	}

	priority_queue<int,vector<int>,greater<int>> pq;

	int sum = 0, ans = 0;

	for(int i = 0; i < n; i ++){
		if(a[i] >= 0){
			pq.push(a[i]);
			sum += a[i];
		}
		else{
			sum += a[i];
			if(sum >= 0){
				pq.push(a[i]);
			}
			else{
				pq.push(a[i]);
				while(!pq.empty()){
					sum -= pq.top();
					pq.pop();
					if(sum >= 0){
						break;
					}
				}
			}
		}
		ans = max(ans,int(pq.size()));
	}
	cout << ans << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}