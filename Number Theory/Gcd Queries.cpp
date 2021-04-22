/*
* https://www.codechef.com/problems/GCDQ
*/

#include<bits/stdc++.h>
using namespace std;

int64_t a[100001] = {};
int64_t ST[400001] = {};

class GCDST{
public:
	 void build(int64_t Si,int64_t Ss,int64_t Se){
	 	if(Ss == Se){
	 		ST[Si] = a[Ss];
	 		return;
	 	}
	 	int64_t mid = (Ss + Se)/2;
	 	build(2*Si,Ss,mid);
	 	build(2*Si+1,mid+1,Se);
	 	ST[Si] = __gcd(ST[2*Si],ST[2*Si+1]);
	 }
	 int64_t query(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
	 	if(Qs > Se or Qe < Ss)return 0;
	 	if(Qs <= Ss and Qe >= Se)return ST[Si];
	 	int64_t mid = (Ss+Se)/2;
	 	return __gcd(query(2*Si,Ss,mid,Qs,Qe),query(2*Si+1,mid+1,Se,Qs,Qe));
	 }
};

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	GCDST tree;
	int64_t i,j,t=1;
	cin>>t;
	while(t--){
		int64_t n;cin>>n;
		int64_t r;cin>>r;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		tree.build(1,1,n);
		while(r--){
			int64_t l,r;cin>>l>>r;
			int64_t gcd1 = 0;
			if(l-1>=1) gcd1 = tree.query(1,1,n,1,l-1);
			int64_t gcd2 = 0;
			if(r+1<=n) gcd2 = tree.query(1,1,n,r+1,n);
			cout<<__gcd(gcd1,gcd2)<<'\n';
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}