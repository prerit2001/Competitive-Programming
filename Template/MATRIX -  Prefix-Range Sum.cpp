int n = grid.size();
int m = grid[0].size();
vector<vector<int>> pre(n, vector<int>(m, 0));
for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j ++){
        pre[i][j] = grid[i][j];
        if(i > 0) pre[i][j] += pre[i - 1][j];
        if(j > 0) pre[i][j] += pre[i][j - 1];
        if(i > 0 and j > 0) pre[i][j] -= pre[i - 1][j - 1];
    }
}
function<int(int,int,int,int)> getSum = [&](int XU, int YU, int XD, int YD){
    int ans = pre[XD][YD];
    if(XU > 0) ans -= pre[XU - 1][YD];
    if(YU > 0) ans -= pre[XD][YU - 1];
    if(XU > 0 and YU > 0) ans += pre[XU - 1][YU - 1];
    return ans;
};