/*https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a8e6*/

#include<bits/stdc++.h>
using namespace std;
// #define int64_t uint64_t

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
// 	#ifndef ONLINE_JUDGE
// 	freopen("E:/CODING/input.txt", "r", stdin); 
// 	freopen("E:/CODING/output.txt", "w", stdout); 
// 	#endif

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
	int64_t K = 0;
	while(t--){
		K++;
		cout << "Case #" << K << ": ";
		int64_t n; cin >> n;
		int64_t left = 2, right = 1e9;
		while(left < right){
			int64_t mid = (left + right + 1)/2;
			int64_t store_mid = mid;
			vector<int64_t> temp;
			while(temp.size() < 2){
				if(miller_rabin_accurate_prime(mid)){
					temp.push_back(mid);
				}
				mid++;
			}
			if((temp[0] * temp[1]) > n){
				right = store_mid - 1;
			}
			else{
				left = store_mid;
			}
		}
		vector<int64_t> temp;
		while(temp.size() < 2){
			if(miller_rabin_accurate_prime(left)){
				temp.push_back(left);
			}
			left++;
		}
		cout << temp[0] * temp[1] << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}