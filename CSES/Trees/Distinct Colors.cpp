#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int limit = 2e5+5;
vector<int> adj[limit];
int c[limit];
bool vis[limit];
map<int,int> color;
int starttime[limit];
int endtime[limit];
int timer;
int segment_array[limit];
set<int> ST[4*limit];

class RDQST{
public:
	void buildTree(int Si, int Ss, int Se){
		if(Ss == Se){
			ST[Si].insert(segment_array[Ss]);
			return;
		}
		int mid = (Ss+Se)/2;
		buildTree(2*Si,Ss,mid);
		buildTree(2*Si+1,mid+1,Se);
		ST[Si].insert(ST[2*Si].begin(),ST[2*Si].end());
		ST[Si].insert(ST[2*Si+1].begin(),ST[2*Si+1].end());
	}
	set<int> answeringQueries(int Si, int Ss, int Se, int Qs, int Qe){
		set<int> empty;
		if(Ss > Qe or Se < Qs) return empty;
		if(Ss >= Qs and Se <= Qe) return ST[Si];
		set<int> result;
		int mid = (Ss+Se)/2;
		set<int> left = answeringQueries(2*Si,Ss,mid,Qs,Qe);
		set<int> right = answeringQueries(2*Si+1,mid+1,Se,Qs,Qe);
		result.insert(left.begin(), left.end());
		result.insert(right.begin(), right.end());
		return result;
	}
};

void dfs(int curr){
	vis[curr] = 1;
	timer ++;
	starttime[curr] = timer;
	for(auto v : adj[curr]){
		if(!vis[v]){
			dfs(v);
		}
	}
	timer ++;
	endtime[curr] = timer;
}

void solve(int i = 0, int j = 0){
	int n; cin >> n;
	for(i=0;i<n;i++){
		cin >> c[i];
	}
	for(i=0;i<n-1;i++){
		int u,v; cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	memset(vis,0,sizeof vis);
	dfs(0);
	for(i=0;i<n;i++){
		color[starttime[i]] = c[i];
	}
	vector<int> start_time;
	for(i=0;i<n;i++){
		start_time.push_back(starttime[i]);
	}
	sort(start_time.begin(), start_time.end());
	for(i=0;i<n;i++){
		segment_array[i] = color[start_time[i]];
	}
	RDQST segTree;
	segTree.buildTree(1,0,n-1);
	for(i=0;i<n;i++){
		int intime = starttime[i];
		int outtime = endtime[i];
		int L = lower_bound(start_time.begin(), start_time.end(),intime) - start_time.begin();
		int R = upper_bound(start_time.begin(), start_time.end(),outtime) - start_time.begin() - 1;
		cout << segTree.answeringQueries(1,0,n-1,L,R).size() << " ";
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}