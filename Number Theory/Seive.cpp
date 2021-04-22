#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	// 1-based index
	bool a[1000001];
	memset(a,true,sizeof(a));
	auto seive = [&](){
		a[0] = false;
		a[1] = false;
		for(int64_t i=2;i*i<=1000001;i++){
			if(a[i])
			for(int64_t j=i*i;j<=1000001;j+=i){
				a[j]&=false;
			}
		}
	};
	seive();

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n;cin>>n;
		for(i=1;i<=n;i++){
			if(a[i]){
				cout<<i<<" ";
			}
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}