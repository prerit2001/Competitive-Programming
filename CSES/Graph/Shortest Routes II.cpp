/*
Floyd Warshal Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n,m,q; cin >> n >> m >> q;
		int64_t graph[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				graph[i][j] = LLONG_MAX;
				if(i==j){
					graph[i][j] = 0;
				}
			}
		}
		for(i=0;i<m;i++){
			int64_t u,v,w; cin >> u >> v >> w;
			graph[u-1][v-1] = min(w,graph[u-1][v-1]);
			graph[v-1][u-1] = min(w,graph[v-1][u-1]);
		}



		for(int64_t k=0;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(graph[i][k]!=LLONG_MAX and graph[k][j]!=LLONG_MAX){
						if(graph[i][j] > graph[i][k] + graph[k][j]){
							graph[i][j] = graph[i][k] + graph[k][j];
						}
					}
				}
			}
		}

		while(q --){
			int64_t u,v; cin >> u >> v;
			if(graph[u-1][v-1] == LLONG_MAX)
				cout << "-1\n";
			else	
				cout << graph[u-1][v-1] << '\n';
		}
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}