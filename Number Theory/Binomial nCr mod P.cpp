#include<bits/stdc++.h>
using namespace std;

int64_t fact[1000001] = {1,1,2};

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	auto power = [&](int64_t a,int64_t b,int64_t mod){
	    int64_t res = 1;
        while(1){
    		if(b==0){
    			break;
    		}
    		int64_t cnt = 1;
    		int64_t curr = a % mod;
    		while(cnt * 2 < b){
    			curr = (curr%mod*curr%mod)%mod;
    			cnt *= 2;
    		}
    		res = (res%mod*curr%mod)%mod;
    		b -= cnt;
    	}
    	return (res%mod+mod)%mod;
	};

	auto ModInv = [&](int64_t a,int64_t mod){
		return power(a,mod-2,mod);
	};

	auto nCr = [&](int64_t n,int64_t r,int64_t mod){
		int64_t numirator = fact[n];
		int64_t denominator = 0;
		if(n >= r) denominator = (fact[n-r]%mod * fact[r]%mod)%mod;
		return r > n ? 0 : ((numirator%mod)*ModInv(denominator,mod)%mod)%mod;
	};

	int64_t mod = 1e9+7;
	for(int64_t i=3;i<1000005;i++){
		fact[i] = (i%mod*fact[i-1]%mod)%mod;
	}

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		cout<<nCr(1e6,2e4+2,mod);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}