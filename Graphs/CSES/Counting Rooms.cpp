/*
  // grid bfs/dfs
*/


#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 1e3 + 5;
string s[LIMIT];
bool vis[LIMIT][LIMIT];

int64_t dx[] = {0,0,1,-1};
int64_t dy[] = {1,-1,0,0};
string ds = "RLDU";

int64_t N,M;

bool possible(int64_t curr_x,int64_t curr_y){
	return curr_x >= 0 and curr_x < N and curr_y >= 0 and curr_y < M;
}

void dfs(int64_t curr_x, int64_t curr_y){
	if(!possible(curr_x,curr_y)){
		return;
	}
	if(vis[curr_x][curr_y]){
		return;
	}
	if(s[curr_x][curr_y] != '.'){
		return;
	}
	vis[curr_x][curr_y] = true;
	for(int i=0;i<4;i++){
		int64_t next_x = curr_x + dx[i];
		int64_t next_y = curr_y + dy[i];
		dfs(next_x,next_y);
	}
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	// cin>>t;
	while(t--){
		int64_t n,m; cin >> n >> m;
		N = n, M = m;
		for(int i=0;i<n;i++){
			cin >> s[i];
		}

		memset(vis,false,sizeof(vis));
		int64_t cnt = 0;
		
		// dfs traverseal of the graph to find the connected components
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!vis[i][j] and s[i][j] == '.'){
					cnt ++;
					dfs(i,j);
				}
			}
		}

		// bfs traverseal of the graph to find the connected components
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++){
		// 		if(!vis[i][j] and s[i][j] == '.'){
		// 			cnt ++;
		// 			queue<pair<int,int>> q;
		// 			q.push({i,j});
		// 			vis[i][j] = true;
		// 			while(!q.empty()){
		// 				int64_t curr_x = q.front().first;
		// 				int64_t curr_y = q.front().second;
		// 				q.pop();
		// 				for(int k=0;k<4;k++){
		// 					int64_t next_x = curr_x + dx[k];
		// 					int64_t next_y = curr_y + dy[k];
		// 					if(!possible(next_x,next_y)){
		// 						continue;
		// 					}
		// 					if(vis[next_x][next_y]){
		// 						continue;
		// 					}
		// 					if(s[next_x][next_y] != '.'){
		// 						continue;
		// 					}
		// 					vis[next_x][next_y] = true;
		// 					q.push({next_x,next_y});
		// 				}
		// 			}
		// 		}
		// 	}
		// }

		// since number of connected rooms is always equal to the the number
		// of connected components of floors.
		cout << cnt << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}