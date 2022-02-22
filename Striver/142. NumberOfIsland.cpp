/*https://leetcode.com/problems/number-of-islands/*/
/*
	M1: DFS
	Time Complexity: O(N * M) Space Complexity: O(N * M)
*/
#include <vector>

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

/*
    dx[] and dy[] are the arrays that define each of the eight directions.

    dx[0], dy[0] : West
    dx[1], dy[1] : North-West
    dx[2], dy[2] : North
    dx[3], dy[3] : North-East
    dx[4], dy[4] : East
    dx[5], dy[5] : South-East
    dx[6], dy[6] : South
    dx[7], dy[7] : South-West

*/

vector<vector<bool>> vis;

void getTotalIslandsHelper(int** mat, int n, int m, int x, int y)
{
    // Check if this cell is valid.
    if(!(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y]))
    {
        return;
    }

    vis[x][y] = true;

    for(int i=0; i<8; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        getTotalIslandsHelper(mat, n, m, nextX, nextY);
    }
}

int getTotalIslands(int** mat, int n, int m)
{
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    int islands = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j])
            {
                // We have found an undiscovered island.
                islands++;
                getTotalIslandsHelper(mat, n, m, i, j);
            }
        }
    }

    return islands;
}

/*
	M2: BFS
	Time Complexity: O(N * M) Space Complexity: O(N * M)
*/
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