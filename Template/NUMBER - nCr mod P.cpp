#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int fact[100005] = {1,1,2,6};

int mod = 998244353;

int power(int x,int y, int p){
    int res = 1;  
    x = x % p;
    if (x == 0) return 0; 
 
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

int ModInv(int a,int mod){
	return power(a,mod-2,mod)%mod;
};

int ncr(int n,int r,int mod){
	if(r > n) return 0;
	if(r == 0 or r == n) return 1;
	int numirator = fac[n];
	int denominator = ((fac[n-r]%mod) * (fac[r]%mod))%mod;
	return ((numirator%mod)*(ModInv(denominator,mod)%mod))%mod;
};

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int mod = 1e9+7;
	for(int i=3;i<1000005;i++){
		fact[i] = (i%mod*fact[i-1]%mod)%mod;
	}

	int i,j,t=1;
	while(t--){
		cout << nCr(1e6,2e4+2,mod) << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
