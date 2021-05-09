/*
This is still a pretty large number of bases. So people have 
invested quite a lot of computation power into finding lower bounds. 
It turns out, for testing a 32 bit integer it is only necessary to 
check the first 4 prime bases: 2, 3, 5 and 7. The smallest composite
number that fails this test is 3,215,031,751=151⋅751⋅28351. 
And for testing 64 bit integer it is enough to check the 
first 12 prime bases: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
*/

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

	auto miller_rabin_accurate_prime = [&](int64_t n){
		bool ok = true;
		if(n<=38){
			ok = false;
			for(int random_a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
				if(n == random_a){
					ok = true;
					break;
				}
			}	
		}
		else{
			int64_t s = 0;
			int64_t d = n - 1;
			while(d%2 == 0){
				d /= 2;
				s ++;
			}
			for(int random_a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
				// checking composite
				// checking wheather n divies one of the factors
				int64_t x = power(random_a,d,n);
				bool check = false;
				if(x == 1 or x == n - 1){
					check |= true;
				}
				else{
					for(int r = 0; r < s; r ++){
						x = (x%n*x%n)%n;
						if(x == n-1){
							check |= true;
							break;
						}
					}
				}
				ok &= check;
			}
		}
		return ok;
	};

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n; cin >> n;
		cout << (miller_rabin_accurate_prime(n) ? "YES\n" : "NO\n");
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}