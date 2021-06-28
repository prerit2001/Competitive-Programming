#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 1e5+5;
int BIT[limit];

class FenwickTree{
public:
	int n;
	FenwickTree(int n){
		this->n = n + 1;
		for(int i = 0; i <= n + 1; i ++){
			BIT[i] = 1e15; 
		}
	}
	void update(int idx, int value){
		while(idx <= n){
			BIT[idx] = min(BIT[idx],value);
			idx += (idx&(-idx));
		}
	}
	int pre_min(int idx){
		int mini = 1e15;
		while(idx > 0){
			mini = min(BIT[idx],mini);
			idx -= (idx&(-idx));
		}
		return mini;
	}
	/* Not possible to solve min between ranges l to r, coz BIT is restricted to solve queries of form [1:L],
	   and there is no trick to get value of min from L to R from BIT; 
		int range_min(int l, int r){

		}
	*/
};

void solve(){
	int n; cin >> n;
	FenwickTree fenTree(n);
	int a[n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		fenTree.update(i+1,a[i] - 0); // since idx starts with 1, *** change value at idx to val then add (val - a[idx]) to a[idx] *** 
	}
	
	cout << fenTree.pre_min(4) << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	
}