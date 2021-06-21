#include<bits/stdc++.h>
using namespace std;
#define int int

// 1-based index
bool a[1000001];

void seive(){
	memset(a,true,sizeof(a));
	a[0] = false;
	a[1] = false;
	for(int i=2;i*i<=1000001;i++){
		if(a[i])
		for(int j=i*i;j<=1000001;j+=i){
			a[j]&=false;
		}
	}
};

signed main(){

	ios_base::sync_with_`stdio(false);cin.tie(NULL); 

	// 1-based index
	seive();

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n;cin>>n;
		for(i=1;i<=n;i++){
			if(a[i]){
				cout<<i<<" ";
			}
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}