// Range Sum Query

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int a[100001] = {};
int ST[400001] = {};
int lazyDiary[400001] = {};

// Range sum Query with Range Updates
class RUQSQ{
public:
	void buildTree(int Si,int Ss,int Se){
		if(Ss == Se){
			ST[Si] = a[Ss];
			return;
		}
		int mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST[Si] = ST[2*Si] + ST[2*Si+1];
	}
	int answeringQueries(int Si,int Ss,int Se,int Qs,int Qe){	
		// Firstly checking pending updates on the node we gonna proceed
		if(lazyDiary[Si] != 0){
			if(Ss != Se){	
				lazyDiary[2*Si] += lazyDiary[Si];
				lazyDiary[2*Si+1] += lazyDiary[Si];
			}
			ST[Si] += lazyDiary[Si] * (Se - Ss + 1);
			lazyDiary[Si] = 0;
		}

		if(Qe < Ss or Se < Qs)return 0;
		if(Qs <= Ss and Se <= Qe)return ST[Si];
		int mid = (Ss + Se)/2;
		return answeringQueries(2*Si,Ss,mid,Qs,Qe) + answeringQueries(2*Si+1,mid+1,Se,Qs,Qe);
	}
	void updateRange(int Si,int Ss,int Se,int Qs,int Qe,int val){
		// Firstly checking pending updates on the node we gonna proceed
		if(lazyDiary[Si]!=0){
			if(Ss != Se){
				lazyDiary[2*Si] += lazyDiary[Si];
				lazyDiary[2*Si+1] += lazyDiary[Si];
			}
			ST[Si] += lazyDiary[Si] * (Se - Ss + 1);
			lazyDiary[Si] = 0;
		}
		
		if(Qe < Ss or Se < Qs)return;
		if(Qs <= Ss and Se <= Qe){
			if(Ss != Se){
				lazyDiary[2*Si] += val;
				lazyDiary[2*Si+1] += val;
			}
			ST[Si] += val * (Se - Ss + 1);
			return;
		}
		int mid = (Ss + Se)/2;
		updateRange(2*Si,Ss,mid,Qs,Qe,val);
		updateRange(2*Si+1,mid+1,Se,Qs,Qe,val);
		ST[Si] = ST[2*Si] + ST[2*Si+1];
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/error.txt", "w", stderr); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif
	int n;cin>>n;
	int i=0;
	for(i=1;i<=n;i++)cin>>a[i];

	//BUILD TREE
	RUQSQ tree;
	tree.buildTree(1,1,n);

	int q;cin>>q;
	while(q--){
		int Q,l,r;cin>>Q>>l>>r;
		//RANGE SUM
		if(Q == 1){
			cout<<tree.answeringQueries(1,1,n,l,r)<<endl;
		}
		//UPDATE
		if(Q == 2){
			int val;cin>>val;
			tree.updateRange(1,1,n,l,r,val);
		}
	}
	return 0;
}