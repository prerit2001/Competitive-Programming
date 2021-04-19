#include<bits/stdc++.h>
using namespace std;

map<vector<int64_t>,int64_t> mp;

int64_t go(vector<int64_t> v){

	if(v.size() == 1){
		return 0;
	}
	if(mp.count(v))return mp[v];

	int64_t n = v.size();
	int64_t smallest=v[0]+v[1];
	int64_t idx1 = 0, idx2 = 1;
	int64_t choice = LLONG_MAX;

	for(int i=0;i<n-1;i++){
		vector<int64_t> a;
		for(int j=0;j<n;j++){
			if(j==i){
				a.push_back(v[i]+v[i+1]);
			}
			else{
				if(j!=i+1){
					a.push_back(v[j]);
				}
			}
		}
		choice = min(choice,v[i]+v[i+1]+go(a));
	}

	return mp[v] = choice;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	// cin>>t;
	int i,j;
	while(t--){
		int64_t n;cin>>n;
		vector<int64_t> a(n);
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<go(a);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}