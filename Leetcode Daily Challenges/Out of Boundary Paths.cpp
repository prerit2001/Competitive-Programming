// DP
class Solution {
public:
    int mod = 1e9 + 7;
    bool init = 0;
    int dp[51][51][51];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    bool possible(int row, int col, int n, int m){
        return (row >= 0 and col >= 0 and row < n and col < m); 
    }
    int findPaths(int n, int m, int move, int row, int col){
        if(init == 0){
            init = 1;
            memset(dp, -1, sizeof dp);
        }
        if(!possible(row,col,n,m)){
            if(move >= 0) return 1;
            return 0;
        }
        if(move == 0) return 0;
        if(dp[row][col][move] != -1) return dp[row][col][move] % mod; 
        int ans = 0;
        for(int i = 0; i < 4; i ++){
            ans = (ans % mod + findPaths(n,m,move-1,row+dx[i],col+dy[i]) % mod) % mod;
        }
        return (dp[row][col][move] = ans) % mod;
    }
};