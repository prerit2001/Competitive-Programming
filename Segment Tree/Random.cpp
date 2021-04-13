/*
n<100000,q<1000000
query type 1 : ? : find maximum |a[1]-a[i]| + |b[1]-b[i]|
query type 2 : 'a' X Y : Replace a[X] = Y
query type 2 : 'b' X Y : Replace b[X] = Y
*/

#include<bits/stdc++.h>
using namespace std;

int i,j;

int64_t ST1[1600001];
int64_t ST2[1600001];
int64_t ST3[1600001];
int64_t ST4[1600001];
int64_t a1[400001];
int64_t a2[400001];
int64_t b1[400001];
int64_t b2[400001];

class RMQSQ1{
public:
	void buildTree(int64_t Si,int64_t Ss,int64_t Se){
		if(Ss == Se){
			ST1[Si] = a1[Ss];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST1[Si] = min(ST1[2*Si],ST1[2*Si+1]); 
	}
	int64_t answeringQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(Ss > Qe or Se < Qs)return LLONG_MAX; // Completly Outside
		if(Ss >= Qs and Qe >= Se)return ST1[Si];
		int64_t mid = (Ss + Se)/2;
		return min(answeringQueries(2*Si,Ss,mid,Qs,Qe),answeringQueries(2*Si+1,mid+1,Se,Qs,Qe));
	}
	void updateQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Q){
		if(Ss == Se){
			ST1[Si] = a1[Q];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		if(Q <= mid  and Q >= Ss)updateQueries(2*Si,Ss,mid,Q);
		else updateQueries(2*Si+1,mid+1,Se,Q);
		ST1[Si] = min(ST1[2*Si],ST1[2*Si+1]);
	}
};

class RMQSQ2{
public:
	void buildTree(int64_t Si,int64_t Ss,int64_t Se){
		if(Ss == Se){
			ST2[Si] = b1[Ss];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST2[Si] = min(ST2[2*Si],ST2[2*Si+1]); 
	}
	int64_t answeringQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(Ss > Qe or Se < Qs)return LLONG_MAX; // Completly Outside
		if(Ss >= Qs and Qe >= Se)return ST2[Si];
		int64_t mid = (Ss + Se)/2;
		return min(answeringQueries(2*Si,Ss,mid,Qs,Qe),answeringQueries(2*Si+1,mid+1,Se,Qs,Qe));
	}
	void updateQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Q){
		if(Ss == Se){
			ST2[Si] = b1[Q];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		if(Q <= mid  and Q >= Ss)updateQueries(2*Si,Ss,mid,Q);
		else updateQueries(2*Si+1,mid+1,Se,Q);
		ST2[Si] = min(ST2[2*Si],ST2[2*Si+1]);
	}
};

class RMXQSQ1{
public:
	void buildTree(int64_t Si,int64_t Ss,int64_t Se){
		if(Ss == Se){
			ST3[Si] = a2[Ss];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST3[Si] = max(ST3[2*Si],ST3[2*Si+1]);
	}
	int64_t answeringQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(Qs > Se or Qe < Ss)return LLONG_MIN;
		if(Qs <= Ss and Qe >= Se)return ST3[Si];
		int64_t mid = (Ss + Se)/2;
		return max(answeringQueries(2*Si,Ss,mid,Qs,Qe),answeringQueries(2*Si,mid+1,Se,Qs,Qe));
	}
	void updateQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Q){
		if(Ss == Se){
			ST3[Si] = a2[Q];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		if(mid <= Q  and Q >= Ss) updateQueries(2*Si,Ss,mid,Q);
		else updateQueries(2*Si+1,mid+1,Se,Q);
		ST3[Si] = max(ST3[2*Si],ST3[2*Si+1]);
	}
};

class RMXQSQ2{
public:
	void buildTree(int64_t Si,int64_t Ss,int64_t Se){
		if(Ss == Se){
			ST4[Si] = b2[Ss];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST4[Si] = max(ST4[2*Si],ST4[2*Si+1]);
	}
	int64_t answeringQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Qs,int64_t Qe){
		if(Qs > Se or Qe < Ss)return LLONG_MIN;
		if(Qs <= Ss and Qe >= Se)return ST4[Si];
		int64_t mid = (Ss + Se)/2;
		return max(answeringQueries(2*Si,Ss,mid,Qs,Qe),answeringQueries(2*Si,mid+1,Se,Qs,Qe));
	}
	void updateQueries(int64_t Si,int64_t Ss,int64_t Se,int64_t Q){
		if(Ss == Se){
			ST4[Si] = b2[Q];
			return;
		}
		int64_t mid = (Ss + Se)/2;
		if(Q <= mid and Q >= Ss) updateQueries(2*Si,Ss,mid,Q);
		else updateQueries(2*Si+1,mid+1,Se,Q);
		ST4[Si] = max(ST4[2*Si],ST4[2*Si+1]);
	}
};

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	// cin>>t;
	while(t--){
		int64_t n,q;cin>>n>>q;
		int64_t a[n],b[n];
		for(i=0;i<n;i++){
			cin>>a[i];
			// one based index
			a1[i+1] = a[i];
			a2[i+1] = a[i];
		}
		for(i=0;i<n;i++){
			cin>>b[i];
			// one based index
			b1[i+1] = b[i];
			b2[i+1] = b[i];
		}
		
		RMQSQ1 A_MIN_TREE;
		RMXQSQ1 A_MAX_TREE;
		RMQSQ2 B_MIN_TREE;
		RMXQSQ2 B_MAX_TREE;

		A_MIN_TREE.buildTree(1,1,n); 
		B_MIN_TREE.buildTree(1,1,n); 
		A_MAX_TREE.buildTree(1,1,n); 
		B_MAX_TREE.buildTree(1,1,n);

		while(q--){
			char c;cin>>c;
			if(c == '?'){
				int64_t a_max = max(abs(a1[1] - A_MIN_TREE.answeringQueries(1,1,n,1,n)),abs(a1[1] - A_MAX_TREE.answeringQueries(1,1,n,1,n)));
				int64_t b_max = max(abs(b1[1] - B_MIN_TREE.answeringQueries(1,1,n,1,n)),abs(b1[1] - B_MAX_TREE.answeringQueries(1,1,n,1,n)));
				cout<<"Query Answer : "<<a_max+b_max<<'\n';
				continue;
			}
			int64_t Q,V;cin>>Q>>V;
			if(c == 'a'){
				a1[Q] = V;
				a2[Q] = V;
				A_MIN_TREE.updateQueries(1,1,n,Q);
				A_MAX_TREE.updateQueries(1,1,n,Q);
				continue;
			}
			if(c == 'b'){
				b1[Q] = V;
				b2[Q] = V;
				B_MIN_TREE.updateQueries(1,1,n,Q);
				B_MAX_TREE.updateQueries(1,1,n,Q);
				continue;
			}
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}