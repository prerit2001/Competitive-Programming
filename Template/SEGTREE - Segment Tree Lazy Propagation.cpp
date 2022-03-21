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

------------------------------------------------------


class segTree {
public:
	ll n;
	vector<ll> a;
	vector<ll> St;
	vector<ll> lazyDiary;
	void segBuild(ll n, vector<ll> a) {
		this->n = n;
		this->a.resize(n + 1, 0);
		for (ll i = 0; i < n; i++) {
			this->a[i + 1] = a[i];
		}
		St.resize(5 * n);
		lazyDiary.resize(5 * n);
		build(1, 1, n);
	}
	void build(ll Si, ll Ss, ll Se) {
		if (Ss == Se) {
			St[Si] = a[Ss];
			return;
		}
		ll mid = (Ss + Se) >> 1;
		build(2 * Si, Ss, mid);
		build(2 * Si + 1, mid + 1, Se);
		St[Si] = (St[2 * Si] + St[2 * Si + 1]);
	}
	ll query(ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
		if(lazyDiary[Si] != 0){
			if(Ss != Se){	
				lazyDiary[2*Si] += lazyDiary[Si];
				lazyDiary[2*Si+1] += lazyDiary[Si];
			}
			St[Si] += lazyDiary[Si] * (Se - Ss + 1);
			lazyDiary[Si] = 0;
		}
		if (Qs > Se or Qe < Ss) return 0;
		if (Qs <= Ss and Qe >= Se) return St[Si];
		ll mid = (Ss + Se) >> 1;
		ll lSubTree = query(2 * Si, Ss, mid, Qs, Qe);
		ll rSubTree = query(2 * Si + 1, mid + 1, Se, Qs, Qe);
		return (lSubTree + rSubTree);
	}
	void update(ll Si, ll Ss, ll Se, ll Qs, ll Qe, ll val) {
		if(lazyDiary[Si]!=0){
			if(Ss != Se){
				lazyDiary[2*Si] += lazyDiary[Si];
				lazyDiary[2*Si+1] += lazyDiary[Si];
			}
			St[Si] += lazyDiary[Si] * (Se - Ss + 1);
			lazyDiary[Si] = 0;
		}
		if(Qe < Ss or Se < Qs)return;

		if(Qs <= Ss and Se <= Qe){
			if(Ss != Se){
				lazyDiary[2*Si] += val;
				lazyDiary[2*Si+1] += val;
			}
			St[Si] += val * (Se - Ss + 1);
			return;
		}

		ll mid = (Ss + Se) >> 1;
		update(2 * Si, Ss, mid, Qs, Qe, val);
		update(2 * Si + 1, mid + 1, Se, Qs, Qe, val);
		St[Si] = (St[2 * Si] + St[2 * Si + 1]);
	}
};
