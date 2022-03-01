/*https://leetcode.com/problems/ones-and-zeroes/*/
/*
	M1: Rec + Memo
	O(len * n * m) time
*/
/*
	M2: Tabulation
	O(len * n * m) time 
*/
    int dp[601][101][101];
    pair<int,int> countZerosandOne(string s){
        int zero = 0,one = 0;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0')
                zero++;
            else
                one++;
        }
        
        return {zero,one};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i<=strs.size();i++){
            pair<int,int> temp = countZerosandOne(strs[i-1]);
            for(int j = 0;j<=m;j++){
                for(int k = 0;k<=n;k++){
                    if(temp.first <= j and temp.second <= k)
                        dp[i][j][k] = max(1 + dp[i-1][j-temp.first][k-temp.second], dp[i-1][j][k]);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        
        return dp[strs.size()][m][n];
        
    }
