#include<bits/stdc++.h>
using namespace std;
#define int int64_t

// ....check gcd once before
void prime_factorisation(int param){
	map<int,int> mp;
	for(int i=2;i*i<=param;i++){
		if(param%i==0){
			while(param%i==0){
				mp[i]++;
				param=param/i;
			}
		}
	}
	if(param > 1) mp[param]++;

	for(auto it : mp){
		for(int i = 0; i < it.second; i ++){
			cout << it.first << " " ;
		}
	}
	cout << '\n';
};

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n;cin>>n;
		prime_factorisation(n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}