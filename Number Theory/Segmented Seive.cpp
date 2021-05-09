#include<bits/stdc++.h>
using namespace std;

int64_t prime[1000005];
int64_t ans[1000005] = {};

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	for(int64_t i=0;i<1000005;i++){
		prime[i] = 1;
	}
	auto sieve = [&](){
		prime[0] = prime[1] = 0;
		for(int64_t i=2;i*i<1000005;i++){
			if(prime[i])
			for(int64_t j=i*i;j<1000005;j+=i){
				prime[j] = 0; 
			}
		}
	};
	sieve();

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t l,r;cin>>l>>r;
		if(l == 1){
			for(i=1;i<=r;i++){
				if(prime[i]){
					cout << i << '\n';
				}
			}
			cout << '\n';
			continue;
		}
		int64_t temp = l;
		for(int64_t i=0;i<1000005;i++){
			ans[i] = 1;
		}
		for(i=2;i*i<=r;i++){
			if(prime[i]){
				int64_t base = (l / i) * i; if (base < l) base += i; 
				int64_t now = base;
				while (now <= r)
				{	
					ans[now - l] = 0;
					now += i;
				}
				if (i == base) ans[base - l] = 1;
			}
		}
		for(i=0;i<r-l+1;i++){
			if(ans[i]){
				cout<<i+l<<'\n';
			}
		}
		cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}