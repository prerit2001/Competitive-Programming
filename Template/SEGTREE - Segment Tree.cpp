// 1 based indexed

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int ST[400001] = {};
int a[100001] = {};

// Range Minimum Query with Point Update
class RMQSQ{
public:
	void buildTree(int Si,int Ss,int Se){
		if(Ss == Se){
			ST[Si] = a[Ss];
			return;
		}
		int mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST[Si] = min(ST[2*Si],ST[2*Si+1]); 
	}
	int answeringQueries(int Si,int Ss,int Se,int Qs,int Qe){
		if(Ss > Qe or Se < Qs)return LLONG_MAX; // Completly Outside
		if(Ss >= Qs and Qe >= Se)return ST[Si];
		int mid = (Ss + Se)/2;
		return min(answeringQueries(2*Si,Ss,mid,Qs,Qe),answeringQueries(2*Si+1,mid+1,Se,Qs,Qe));
	}
	void updateQueries(int Si,int Ss,int Se,int Q){
		if(Ss == Se){
			ST[Si] = a[Q];
			return;
		}
		int mid = (Ss + Se)/2;
		if(Q <= mid and Q >= Ss)updateQueries(2*Si,Ss,mid,Q);
		else updateQueries(2*Si+1,mid+1,Se,Q);
		ST[Si] = min(ST[2*Si],ST[2*Si+1]);
	}
};

signed main(){

	int n;cin>>n;
	int i = 0;
	for(i=1;i<=n;i++)cin>>a[i];
	
	// BUILD TREE
	RMQSQ tree;
	tree.buildTree(1,1,n);

	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		
		// ANSERING QUERIES
		cout<<tree.answeringQueries(1,1,n,l,r)<<endl;
	}
	return 0;
}