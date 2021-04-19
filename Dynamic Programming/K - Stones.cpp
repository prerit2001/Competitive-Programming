#include<bits/stdc++.h>
using namespace std;

int i,j;
int64_t a[105];

int64_t go(int64_t curr,int64_t move,int64_t n){

		go(curr+1,0,n);

}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	cin>>t;
	while(t--){
		int64_t n,k;cin>>n>>k;
		for(i=0;i<n;i++){
			cin>>a[i];
		}

	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}