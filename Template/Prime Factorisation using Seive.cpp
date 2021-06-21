#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int MinFactor[1000001];

void buildMinFactor(){
	memset(MinFactor,-1,sizeof(MinFactor));
	for(int i=2;i<=1000001;i++){	
		if(MinFactor[i]==-1){
			for(int j=i;j<=1000001;j+=i){
				if(MinFactor[j]==-1){
					MinFactor[j] = i;
				}
			}
		}
	}
};

void prime_factorisation(int param){
	map<int,int> mp;
	int cnt = 0;
	while(MinFactor[param] != param){
		mp[MinFactor[param]]++;
		param = param/MinFactor[param];
	}
	mp[MinFactor[param]]++;

	for(auto it : mp){
		for(int i = 0; i < it.second; i ++){
			cout << it.first << " " ;
		}
	}
	cout << '\n';
};

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	buildMinFactor();

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n;cin>>n;
		prime_factorisation(n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}