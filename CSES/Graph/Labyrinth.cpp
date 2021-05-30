/*
  // grid bfs with path
*/


#include<bits/stdc++.h>
using namespace std;
 
const int64_t LIMIT = 1e3 + 5;
string s[LIMIT];
bool vis[LIMIT][LIMIT];
 
int64_t dx[] = {0,0,1,-1};
int64_t dy[] = {-1,1,0,0};
string ds = "LRDU";
 
int64_t N,M;
int64_t length = 1e15;
string ans = "";
bool ok = false;
pair<int64_t,int64_t> parent[LIMIT][LIMIT] = {};
 
bool possible(int64_t curr_x,int64_t curr_y){
	return curr_x >= 0 and curr_x < N and curr_y >= 0 and curr_y < M;
}
 
void bfs(int64_t curr_x, int64_t curr_y){
	queue<pair<int64_t,int64_t>> q;
	q.push({curr_x,curr_y});
	while(!q.empty()){
		// cout << q.size() << '\n';
		int64_t x = q.front().first;
		int64_t y = q.front().second;
		// cout << x << " " << y << endl;
		if(s[x][y] == 'B'){
			ok = true;
			while(1){
				int64_t parent_x = parent[x][y].first;
				int64_t parent_y = parent[x][y].second;
				int64_t curr_x = x;
				int64_t curr_y = y;
				if(s[curr_x][curr_y] == 'A') break;
				if(parent_x < curr_x){
					ans += 'D';
				}
				if(parent_x > curr_x){
					ans += 'U';
				}
				if(parent_y < curr_y){
					ans += 'R';
				}
				if(parent_y > curr_y){
					ans += 'L';
				}
				x = parent_x, y = parent_y;
			}
			reverse(ans.begin(),ans.end());
			length = ans.size();
			break;
		}
		q.pop();
		for(int i=0;i<4;i++){
			int64_t next_x = x + dx[i];
			int64_t next_y = y + dy[i];
			if(!possible(next_x,next_y)){
				continue;
			}
			if(vis[next_x][next_y]){
				continue;
			}
			if(s[next_x][next_y]=='#'){
				continue;
			}	
			vis[next_x][next_y] = true; 	
			parent[next_x][next_y] = {x,y};
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
 
	int64_t t=1;
	// cin>>t;
	while(t--){
		int64_t n,m; cin >> n >> m;
		N = n, M = m;
 
		for(int i=0;i<n;i++){
			cin >> s[i];
		}
 
		memset(vis,false,sizeof(vis));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j] == 'A'){
					bfs(i,j);
				}
			}
		}
 
		if(!ok){
			cout << "NO\n";
			continue;
		}
		else{
			cout << "YES\n";
			cout << length << '\n';
			cout << ans << '\n';
		}
 
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}