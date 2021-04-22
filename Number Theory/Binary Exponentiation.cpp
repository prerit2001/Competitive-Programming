#include<bits/stdc++.h>
using namespace std;

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

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t a,b;cin>>a>>b;
		cout<<power(a,b,int64_t(1e9+7))<<'\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}