#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(){
	int n = rand() % 1000;
	cout << n << '\n';
	int c[n];
	for(int i = 0; i < n; i ++){
		c[i] = rand() % 1000 + 2;
		cout << c[i] << " ";
	}
	cout << '\n';
	for(int i = 0; i < n; i ++){
		cout << rand() % c[i] + 2 << " ";
	}
	cout << '\n';
	for(int i = 0; i < n; i ++){
		cout << rand() % c[i] + 2 << " ";
	}
	cout << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	srand(time(0));
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}