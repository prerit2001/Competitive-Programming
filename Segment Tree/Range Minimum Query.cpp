// 1 based indexed

#include<bits/stdc++.h>
using namespace std;

int64_t ST[400001] = {};
int64_t a[100001] = {};

class RMQSQ{
public:
	void buildTree(int64_t Si,int64_t Ss,int64_t Se){
		if(Ss == Se){
			ST[Si] = a[Ss];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST[Si] = min(ST[2*Si],ST[2*Si+1]); 
	}
	int64_t answeringQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(Ss > Qe or Se < Qs)return INT_MAX; // Completly Outside
		if(Ss >= Qs and Qe >= Se)return ST[Si];
		int64_t mid = (Ss + Se)/2;
		return min(answeringQueries(2*Si,Ss,mid,Qs,Qe),answeringQueries(2*Si+1,mid+1,Se,Qs,Qe));
	}
	void updateQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Q){
		if(Ss == Se){
			ST[Si] = a[Q];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		if(Q <= mid)updateQueries(2*Si,Ss,mid,Q);
		else updateQueries(2*Si+1,mid+1,Se,Q);
		ST[Si] = min(ST[2*Si],ST[2*Si+1]);
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif
	int64_t n;cin>>n;
	int64_t i = 0;
	for(i=1;i<=n;i++)cin>>a[i];
	
	// BUILD TREE
	RMQSQ tree;
	tree.buildTree(1,1,n);

	int64_t q;cin>>q;
	while(q--){
		int64_t l,r;cin>>l>>r;
		
		// ANSERING QUERIES
		cout<<tree.answeringQueries(1,1,n,l,r)<<endl;

	}

}
