// https://leetcode.com/problems/number-of-islands/

class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof vis);
        auto possible = [&](int x, int y) -> bool {
            return (x >= 0 and y >= 0 and x < n and y < m);
        };
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    cnt ++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        pair<int,int> curr = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k ++){
                            int nextx = curr.first + dx[k];
                            int nexty = curr.second + dy[k];
                            if(possible(nextx,nexty))
                                if(!vis[nextx][nexty])
                                    if(grid[nextx][nexty] == '1')
                                        vis[nextx][nexty] = 1, q.push({nextx,nexty});
                        }
                    }
                }
            }   
        }
        return cnt;
    }
};