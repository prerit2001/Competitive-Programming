#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	auto mulmod = [&](uint64_t a, uint64_t b, uint64_t mod){
		int64_t res = 0;
	    while(1){
	    	if(b == 0){
	    		break;
	    	}
	    	int64_t cnt = 1 ;
	    	int64_t curr = a ;
	       	while(cnt * 2 < b){
	    		cnt = cnt * 2;
	    		curr = (2 * curr) % mod;
	    	}
	    	res = (res%mod + curr%mod) % mod;
	    	b -= cnt;
	    }
	    return res%mod;
	};

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		uint64_t a,b,mod; cin >> a >> b >> mod;

		// a = 1e18, b = 1e18 , mod = 1e18
		cout << mulmod(a,b,mod) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}