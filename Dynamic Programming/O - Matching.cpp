#include<bits/stdc++.h>
using namespace std;


int64_t a[25][25];
int64_t sum;
int64_t mod = 1e9+7;

map<pair<set<int64_t>,set<int64_t>>,int64_t> mp;

int64_t go(set<int64_t> row,set<int64_t> col,int64_t n){

	if(row.size() == n and col.size() == n){
		return 1;
	}
	if(mp.count({row,col}))return mp[{row,col}]%mod;
	if(row.size() >= n or col.size() >= n)return 0;

	int64_t ans = 0;
	for(int64_t i=0;i<n;i++){
		for(int64_t j=0;j<n;j++){
			if(a[i][j] == 1){
				if(!row.count(i) and !col.count(j)){
					row.insert(i);
					col.insert(j);
					ans = (ans%mod + go(row,col,n)%mod)%mod;
					row.erase(i);
					col.erase(j);
				}
			}
		}
	}

	return mp[{row,col}] = ans%mod;
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
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		set<int64_t> row,col;
		cout<<go(row,col,n);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}