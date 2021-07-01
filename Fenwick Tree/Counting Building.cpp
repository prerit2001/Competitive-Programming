#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 1e5 + 5;
int BIT[limit]; // init all index with 0 // genrally size of BIT is n + 1

class FenwickTree{
public:
	int n;
	FenwickTree(int n){
		this->n = n + 1;
		for(int i = 0; i <= n + 1; i ++){
			BIT[i] = 0;
		}
	}
	// initially all values of BIT are 0, so update all the delta's first
	void update(int idx, int value){
		while(idx <= n){
			BIT[idx] += value;
			idx += (idx & (-idx)); // eg: let idx = 13 and n = 16, then idx goes like -> 01101 (13) -> 01110 (14) -> 10000 (16)
		}
	}
	// compute sum from [1:l] 
	int pre_sum(int idx){
		int sum = 0;
		while(idx > 0){
			sum += BIT[idx];
			idx -= (idx & (-idx)); // eg: let idx = 13 and n = 16, then idx goes like -> 01101 (13) -> 01100 (12) -> 01000 (8) -> 00000 (0)
		}
		return sum;
	}
	// compute sum from [l:r]
	int range_sum(int l, int r){
		return pre_sum(r) - pre_sum(l - 1);
	}
};

void solve(){
	int n = 5;
	int a[] = {5, 6, 8, 4, 10};
	FenwickTree fenTree(1e5+1);
	vector<int> ans(n);
	for(int i = 0; i < n; i ++){
		ans[i] = fenTree.pre_sum(a[i]);
		fenTree.update(a[i],1);
	}
	for(int i = 0; i < n; i ++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	
}