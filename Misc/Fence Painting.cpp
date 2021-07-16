#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	int a[n],b[n],c[m];
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	for(int i = 0; i < m; i ++) cin >> c[i];
	// impossible
	map<int,int> mpb,mpc;
	for(int i = 0; i < n; i ++){
		if(b[i] != a[i]) mpb[b[i]] ++;
	}
	for(int i = 0; i < m; i ++){
		mpc[c[i]] ++;
	}
	for(auto &[u,v] : mpb){
		if(!mpc.count(u) or v > mpc[u]){
			cout << "NO\n";
			return;
		}
	}
	map<int,vector<int>> mp;
	for(int i = 0; i < n; i ++){
		if(b[i] != a[i]) mp[b[i]].push_back(i);
	}
	int ans[m] = {};
	int last = -1;
	for(int i = m - 1; i >= 0; i --){
		if(mp.count(c[i]) and mp[c[i]].size() > 0){
			a[mp[c[i]].back()] = c[i];
			ans[i] = mp[c[i]].back() + 1;
			mp[c[i]].pop_back();
			last = max(i,last);
		}
	}
	mpb.clear();
	for(int i = 0; i < n; i ++){
		mpb[b[i]] = i;
	}
	for(int i = m - 1; i >= 0; i --){
		if(ans[i] == 0 and last > i){
			ans[i] = ans[last];
		}
		else if(ans[i] == 0 and mpb.count(c[i])){
			ans[i] = mpb[c[i]] + 1;
			last = max(i,last); 
		}
		else if(ans[i] == 0){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < m; i ++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		// cout << t+1 << endl;
		solve();
	}
	
}