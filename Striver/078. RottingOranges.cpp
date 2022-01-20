/*https://leetcode.com/problems/rotting-oranges/*/
---------------------------------------------------------------------------------
/*
	M1: BFS
	O(n) time and O(1) space
*/

	class Solution {
	public:
	    int dx[4] = {1,-1,0,0};
	    int dy[4] = {0,0,1,-1};
	    queue<tuple<int,int,int>> q;
	    vector<vector<int>> a;
	    int cnt = 0;
	    vector<vector<int>> vis;
	    int bfs(int n,int m){
	        int ans = 0;
	        while(!q.empty()){
	            tuple<int,int,int> u = q.front();
	            q.pop();
	            int x = get<0>(u);
	            int y = get<1>(u);
	            int need = get<2>(u);
	            ans = max(ans,need);
	            for(int i=0;i<4;i++){
	                int next_x = x+dx[i];
	                int next_y = y+dy[i];
	                if(next_x < n and next_x >= 0){
	                    if(next_y < m and next_y >= 0){
	                        if(a[next_x][next_y] == 1)
	                        if(vis[next_x][next_y] == 0){
	                            vis[next_x][next_y] = 1;                   
	                            q.push({next_x,next_y,need+1});
	                            cnt --;
	                        }
	                    }
	                }
	            }  
	        }
	        return cnt == 0 ? ans : -1 ; 
	    }
	    int orangesRotting(vector<vector<int>>& grid) {
	        a = grid;
	        int n = a.size();
	        int m = a[0].size();
	        vis.resize(n,vector<int>(m, 0));
	        for(int i=0;i<grid.size();i++){
	            for(int j=0;j<grid[i].size();j++){
	                if(grid[i][j] == 2){
	                    q.push({i,j,0}); 
	                    vis[i][j] = 1;
	                }
	                else if(grid[i][j] == 1){
	                    cnt ++;
	                    vis[i][j] = 0;
	                }
	                else{
	                    vis[i][j] = 0;
	                }
	            }
	        }
	        return bfs(n,m); 
	    }
	};
---------------------------------------------------------------------------------