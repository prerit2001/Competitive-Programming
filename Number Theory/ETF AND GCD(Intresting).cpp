// (1)Σ(n) gcd(i,n) = ? ,  sum of gcd of i with n is ? where i belongs to [1,n]
#include<bits/stdc++.h>
using namespace std;

int64_t phi[1000005];

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	auto factor = [&](int64_t n){
		vector<int64_t> fac;
		for(int64_t i=1;i*i<=n;i++){
			if(n%i == 0){
				fac.push_back(i);
				if(n/i != i)fac.push_back(n/i);
			}
		}
		sort(fac.begin(), fac.end());
		return fac;
	};

	for(int64_t i=0;i<1000005;i++){
		phi[i] = i;
	}
	for(int64_t i=2;i<=1000005;i++){
		if(phi[i] == i){
			for(int64_t j=i;j<=1000005;j+=i){
				phi[j] /= i;
				phi[j] *= i-1;
			}
		}
	}

	auto CountGCD_X = [&](int64_t curr,int64_t n){
		return phi[n/curr];
	};

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n;cin>>n;
		vector<int64_t> fac = factor(n);
		int64_t ans = 0;
		for(auto it : fac){
			ans += it*CountGCD_X(it,n);
		}
		cout<<ans<<endl;
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}