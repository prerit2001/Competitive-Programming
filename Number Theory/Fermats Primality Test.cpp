#include<bits/stdc++.h>
using namespace std;
#define int64_t uint64_t

// for multiplying two 64bit numbers
int64_t mulmod(int64_t a, int64_t b,int64_t mod){
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
}

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

	auto fermats_prime = [&](int64_t n){
		bool ok = true;
		if(n<=4){
			ok &= n==2 || n==3 ;
		}
		else {
			for(int i = 0; i < 10 ; i++){
				int random_a = 2 + rand()%(n-3);
				if(power(random_a,n-1,n) != 1){
					ok &= false;
				}
			}
		}
		return ok;
	};

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n; cin >> n;
		cout << (fermats_prime(n) ? "YES" : "NO") << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}