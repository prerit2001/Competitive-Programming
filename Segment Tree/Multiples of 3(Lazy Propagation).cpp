#include<bits/stdc++.h>
using namespace std;

int64_t a[100001] = {};
int64_t ST[400001][3] = {}; // For Storing all reminder by 3
int64_t lazyDairy[400001] = {};

class RMulQSQ{
public:
	void buildTree(int64_t Si,int64_t Ss,int64_t Se){
		if(Ss == Se){
			ST[Si][0] = a[Ss]%3==0 ? 1 : 0;
			ST[Si][1] = a[Ss]%3==1 ? 1 : 0;
			ST[Si][2] = a[Ss]%3==2 ? 1 : 0;
			return;
		}
		int64_t mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST[Si][0] = ST[2*Si][0] + ST[2*Si+1][0];
		ST[Si][1] = ST[2*Si][1] + ST[2*Si+1][1];
		ST[Si][2] = ST[2*Si][2] + ST[2*Si+1][2];
	}
	int64_t answeringQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(lazyDairy[Si] != 0){
			if(Ss != Se){
				lazyDairy[2*Si] += lazyDairy[Si]%3;
				lazyDairy[2*Si+1] += lazyDairy[Si]%3;
			}
			lazyDairy[Si]%=3;
			while(lazyDairy[Si]>0){
				swap(ST[Si][0],ST[Si][2]);
				swap(ST[Si][1],ST[Si][2]);
				lazyDairy[Si]--;
			}
			lazyDairy[Si] = 0;
		}
		if(Qe < Ss or Se < Qs)return 0;
		if(Qs <= Ss and Se <= Qe)return ST[Si][0];
		int64_t mid = (Ss + Se)/2;
		return answeringQueries(2*Si,Ss,mid,Qs,Qe) + answeringQueries(2*Si+1,mid+1,Se,Qs,Qe);
	}
	void updateQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(lazyDairy[Si] != 0){
			if(Ss != Se){
				lazyDairy[2*Si] += lazyDairy[Si]%3;
				lazyDairy[2*Si+1] += lazyDairy[Si]%3;
			}
			lazyDairy[Si]%=3;
			while(lazyDairy[Si]>0){
				swap(ST[Si][0],ST[Si][2]);
				swap(ST[Si][1],ST[Si][2]);
				lazyDairy[Si]--;
			}
			lazyDairy[Si] = 0;
		}
		if(Qe < Ss or Se < Qs)return;
		if(Ss >= Qs and Se <= Qe){
			swap(ST[Si][0],ST[Si][2]);
			swap(ST[Si][1],ST[Si][2]);
			if(Ss != Se){
				lazyDairy[2*Si] += 1;
				lazyDairy[2*Si+1] += 1;
			}
			return;
		}
		int64_t mid = (Ss + Se)/2;
		updateQueries(2*Si,Ss,mid,Qs,Qe);
		updateQueries(2*Si+1,mid+1,Se,Qs,Qe);
		ST[Si][0] = ST[2*Si][0] + ST[2*Si+1][0];
		ST[Si][1] = ST[2*Si][1] + ST[2*Si+1][1];
		ST[Si][2] = ST[2*Si][2] + ST[2*Si+1][2];
	}
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/error.txt", "w", stderr); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif
	int64_t n,q;cin>>n>>q;
	
	// BUILD TREE
	RMulQSQ tree;
	tree.buildTree(1,1,n);

	while(q--){
		int64_t Q,l,r;cin>>Q>>l>>r;
		l++,r++;
		if(Q == 1){
			// answer
			cout<<tree.answeringQueries(1,1,n,l,r)<<'\n';
		}
		if(Q == 0){
			// update
			tree.updateQueries(1,1,n,l,r);
		}
	}
}