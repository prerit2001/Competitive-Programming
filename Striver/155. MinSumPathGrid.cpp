/*https://leetcode.com/problems/minimum-path-sum/*/
-------------------------------------------------------------------------
/*
	M1: Memo
	O(n^2) time and O(n^2) space
*/
int dp[205][205];
class Solution {
public:
    int MPS(int i, int n, int j, int m, vector<vector<int>>& grid){
        if(i >= n or j >= m){
            if(i == n and j == m - 1){
                return 0;
            }
            else if(j == m and i == n - 1){
                return 0;
            }
            else{
                return 10000000;
            }
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int choice1 = grid[i][j] + MPS(i + 1, n, j, m, grid);
        int choice2 = grid[i][j] + MPS(i, n, j + 1, m, grid);
        return dp[i][j] = min({choice1, choice2});
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return MPS(0, n, 0, m, grid);
    }
};
-------------------------------------------------------------------------
/*
	M2: Tabulation
	O(n^2) time and O(n^2) space
*/
int dp[205][205];
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        for(int i = 2; i <= n; i ++){
            dp[i][0] = 10000000;
        }
        for(int j = 2; j <= m; j ++){
            dp[0][j] = 10000000;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                int val = grid[i - 1][j - 1];
                dp[i][j] = INT_MAX;
                dp[i][j] = min(dp[i][j], val + dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], val + dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
/*
	space can reduce to linear coz current state can only be dependent upon
	previous state
*/
-------------------------------------------------------------------------
/*
	M3: Dijktra Algo
	O(nmlog(nm)) time and O(nm) space
*/
#define pi pair<int,int>
#define priorityqueue pair <int, pi >
class Solution{
    public:
    int minPathSum(vector<vector<int> > &grid){
        int n=grid.size();
        int m=grid[0].size();
        priority_queue <priorityqueue, vector <priorityqueue> , greater <priorityqueue> > pq;
        pq.push({grid[0][0], {0,0}});
       
        int dis[n][m];
        memset(dis,0,sizeof(dis));
         dis[0][0]=grid[0][0];
        int sum;
        while(pq.size()){
             sum=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            if(u==n-1 && v==m-1){
                return sum;
            }
            pq.pop();
            if(v+1<m && (dis[u][v+1]==0  || sum+grid[u][v+1]<dis[u][v+1] ))
            { dis[u][v+1]=sum+grid[u][v+1];
                pq.push({{sum+grid[u][v+1]},{u,v+1}});}
            if(u+1<n && (dis[u+1][v]==0 || sum+grid[u+1][v]<dis[u+1][v]) )
            {  dis[u+1][v]=sum+grid[u+1][v];
                pq.push({sum+grid[u+1][v],{u+1,v}});}
            
        }
        return sum;
    }
};
-------------------------------------------------------------------------