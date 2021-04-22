#include<bits/stdc++.h>
using namespace std;

int64_t MinFactor[1000001];

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	memset(MinFactor,-1,sizeof(MinFactor));
	auto buildMinFactor = [&](){
		for(int64_t i=2;i<=1000001;i++){	
			if(MinFactor[i]==-1){
				for(int64_t j=i;j<=1000001;j+=i){
					if(MinFactor[j]==-1){
						MinFactor[j] = i;
					}
				}
			}
		}
	};
	buildMinFactor();

	auto query = [&](int64_t param){
		int64_t cnt = 0;
		while(MinFactor[param] != param){
			cout<<MinFactor[param]<<" ";
			param = param/MinFactor[param];
		}
		cout<<MinFactor[param]<<'\n';
	};

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n;cin>>n;
		query(n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}