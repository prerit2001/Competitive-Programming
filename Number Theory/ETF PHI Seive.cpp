#include<bits/stdc++.h>
using namespace std;

int64_t phi[1000005];

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

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

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n;cin>>n;
		cout<<phi[n];
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}