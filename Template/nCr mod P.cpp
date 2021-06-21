#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int fact[1000001] = {1,1,2};

int power(int a,int b,int mod){
    int res = 1;
    while(1){
		if(b==0){
			break;
		}
		int cnt = 1;
		int curr = a % mod;
		while(cnt * 2 < b){
			curr = (curr%mod*curr%mod)%mod;
			cnt *= 2;
		}
		res = (res%mod*curr%mod)%mod;
		b -= cnt;
	}
	return (res%mod+mod)%mod;
};

int ModInv(int a,int mod){
	return power(a,mod-2,mod);
};

int nCr(int n,int r,int mod){
	int numirator = fact[n];
	int denominator = 0;
	if(n >= r) denominator = (fact[n-r]%mod * fact[r]%mod)%mod;
	return r > n ? 0 : ((numirator%mod)*ModInv(denominator,mod)%mod)%mod;
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