#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	auto ETF_phi = [&](int64_t N){
		int64_t n = N;
		vector<int64_t> factors;
		for(int64_t i=2;i*i<=n;i++){
			if(n%i == 0){
				factors.push_back(i);
				while(n%i == 0){
					n/=i;
				}
			}
		}
		int64_t ans = N;
		for(auto it : factors){
			ans *= (it - 1);
			ans /= it;
		}
		if(n > 1){
			ans *= (n - 1);
			ans /= n;
		}
		return ans;
	};

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n;cin>>n;
		cout<<ETF_phi(n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}