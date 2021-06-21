/*
   // multi-sourse bfs :- CSES MONSTERs
*/


#include<bits/stdc++.h>
using namespace std;
 
const int64_t LIMIT = 1e3+5;
string s[LIMIT];
bool vis[LIMIT][LIMIT];
int64_t N,M;
pair<int64_t,int64_t> src, dest;
 
int64_t dx[] = {1,-1,0,0};
int64_t dy[] = {0,0,1,-1};
string ds = "DURL";

int64_t monsters[LIMIT][LIMIT] = {};
int64_t man[LIMIT][LIMIT] = {};
pair<int64_t,int64_t> parent[LIMIT][LIMIT] = {};
int64_t ans = -1;
queue<pair<int64_t,int64_t>> q;
 
bool possible(int64_t curr_x,int64_t curr_y){
	return (curr_x >= 0 and curr_x < N and curr_y >=0 and curr_y < M);
}
 
void bfs_monsters(){
	while(!q.empty()){
		int64_t curr_x = q.front().first;
		int64_t curr_y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int64_t next_x = curr_x + dx[i];
			int64_t next_y = curr_y + dy[i];
			if(!possible(next_x,next_y)){
				continue;
			}
			if(vis[next_x][next_y]){
				continue;
			}
			if(s[next_x][next_y] == '#'){
				continue;
			}
			vis[next_x][next_y] = true;
			monsters[next_x][next_y] = monsters[curr_x][curr_y] + 1;
			q.push({next_x,next_y});
		}
	}
}

void bfs_man(){
	while(!q.empty()){
		int64_t curr_x = q.front().first;
		int64_t curr_y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int64_t next_x = curr_x + dx[i];
			int64_t next_y = curr_y + dy[i];
			if(!possible(next_x,next_y)){
				continue;
			}
			if(vis[next_x][next_y]){
				continue;
			}
			if(s[next_x][next_y] == '#'){
				continue;
			}
			vis[next_x][next_y] = true;		
			parent[next_x][next_y] = {curr_x,curr_y};
			man[next_x][next_y] = man[curr_x][curr_y] + 1;
			q.push({next_x,next_y});
		}
	}
}
 
int main(){
 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif
 
	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		int64_t n,m; cin >> n >> m;
		N = n, M = m;
 
		for(i=0;i<n;i++){
			cin>>s[i];
		}
 
		memset(vis,false,sizeof(vis));
		memset(monsters,-1,sizeof(monsters));
 
		// multisource bfs from all monsters
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j] == 'M'){
					q.push({i,j});
					monsters[i][j] = 0;
					vis[i][j] = true;
				}
			}
		}

		bfs_monsters();

		memset(vis,false,sizeof(vis));
		memset(man,-1,sizeof(man));

		//bfs from man
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j] == 'A'){
					src = {i,j};
					q.push({i,j});
					vis[i][j] = true;
					man[i][j] = 0;
				}
			}
		}

		bfs_man();

		int64_t flag = 0;

		//checking all boundary
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(i == 0 or i == n-1 or j == 0 or j == m-1){
					if(man[i][j] != - 1){
						if(monsters[i][j] == -1 or monsters[i][j] > man[i][j]){
							flag = 1;
							dest = {i,j};
							break;
						}
					}
				}
			}
			if(flag == 1)break;
		}

		if(!flag){
			cout << "NO\n";
			continue;
		}

		string ans = "";

		while(1){
			int64_t curr_x = dest.first;
			int64_t curr_y = dest.second;

			int64_t parent_x = parent[curr_x][curr_y].first;
			int64_t parent_y = parent[curr_x][curr_y].second;

			if(curr_x == src.first and curr_y == src.second){
				break;
			}

			if(parent_y > curr_y){
				ans += 'L';
			}
			if(parent_y < curr_y){
				ans += 'R';
			}
			if(parent_x < curr_x){
				ans += 'D';
			}
			if(parent_x > curr_x){
				ans += 'U';
			}

			dest.first = parent_x;
			dest.second = parent_y;
		}

		cout << "YES\n";
		cout << ans.size() << '\n';
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';

	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}