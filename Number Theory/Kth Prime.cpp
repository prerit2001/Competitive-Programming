/*
* https://www.spoj.com/problems/TDKPRIME/
*/
#include<bits/stdc++.h>
using namespace std;

bool a[90000000];

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	// 1-based index
	memset(a,true,sizeof(a));
	auto seive = [&](){
		a[0] = false;
		a[1] = false;
		for(int64_t i=2;i*i<=90000000;i++){
			if(a[i])
			for(int64_t j=i*i;j<=90000000;j+=i){
				a[j]&=false;
			}
		}
	};

	seive();
	vector<int64_t> v;
	v.push_back(2);
	for(int64_t i=3;i<=90000000;i+=2){
		if(a[i])v.push_back(i);
	}

	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n;cin>>n;
		cout<<v[n-1]<<"\n";
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}