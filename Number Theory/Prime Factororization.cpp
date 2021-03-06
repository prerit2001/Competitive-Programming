#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	auto factorization = [&](int64_t param){
		for(int64_t i=2;i*i<=param;i++){
			if(param%i==0){
				while(param%i==0){
					cout<<i<<" ";
					param=param/i;
				}
			}
		}
		if(param > 1) cout<<param<<'\n';
	};

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n;cin>>n;
		factorization(n);	
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}