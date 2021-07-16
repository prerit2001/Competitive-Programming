#include<bits/stdc++.h>
using namespace std;
#define int int64_t

map<tuple<int,int,int>,int> mp;

int b_search(int lim, int dig, int poww){
	if(mp.count({lim,dig,poww})) return mp[{lim,dig,poww}];
	int left = 0, right = 1e10;
	while(left < right){
		int mid = (left + right + 1) >> 1;
		int val = mid * poww + dig;
		if(val > lim){
			right = mid - 1;
		}
		else{
			left = mid;
		}
	}
	return mp[{lim,dig,poww}] = left;
}

void solve(){
	int l,r; cin >> l >> r;

	int ans = 0;
	for(int i = 1; i <= 9; i ++){
		ans += b_search(r,i,10) + (i <= r and i > l) - b_search(l,i,10);
	}

	int power = 1;
	for(int j = 1; j <= 10; j ++){
		power *= 10;
		int curr = j * 10;
		vector<int> store;
		int pp = 10;
		for(int i = 2; i <= 11; i ++){
			pp *= 10;
			store.push_back(b_search(r,curr,pp) - b_search(l,curr,pp) + (curr > l and curr <= r));
			curr = curr * 10;
			if(curr > r) break;
		}
		int sub = 0;
		for(int i = store.size() - 1; i >= 0; i --){
			int val = store[i] - sub;
			ans += (i+2)*val;
			sub = store[i];
		}
	}

	cout << ans << '\n';

}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	// for(int i = 1; i <= 1e4; i ++){
	// 	for(int j = 1; j <= 10; j ++){
	// 		for(int k = 1; k <= 10; j ++){
	// 			b_search(i,j,k);
	// 		}
	// 	}
	// }
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}