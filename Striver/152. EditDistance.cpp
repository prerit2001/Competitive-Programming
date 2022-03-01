/*https://leetcode.com/problems/edit-distance/*/
/*
	M1: Rec + Memo
	O(n * m) time and O(n * m) space 
*/
int dp[505][505]; // operation required for word upto i len comparing to j len in word2
class Solution {
public:
    int editDis(int i, int n, int j, int m, string& a, string& b){
        if(i >= n or j >= m){
            if(i >= n) return m - j;
            else return n - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int choice1 = INT_MAX;
        if(a[i] == b[j]){
            choice1 = editDis(i + 1, n, j + 1, m, a, b);
        }
        int choice2 = 1 + editDis(i + 1, n, j, m, a, b);
        int choice3 = 1 + editDis(i, n, j + 1, m, a, b);
        int choice4 = 1 + editDis(i + 1, n, j + 1, m, a, b);
        return dp[i][j] = min({choice1, choice2, choice3, choice4});
    }
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        memset(dp, -1, sizeof dp);
        if(a.size() == 0) return b.size();
        if(b.size() == 0) return a.size();
        return editDis(0, n, 0, m, a, b);
    }
};
/*
	M2: Tabulation
	O(n * m) time and O(n * m) space 
*/
int dp[505][505]; // operation required for word upto i len comparing to j len in word2
class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        dp[0][0] = 0;
        for(int i = 1; i <= n; i ++){
            dp[i][0] = i;
        }
        for(int j = 1; j <= m; j ++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                char cA = a[i - 1];
                char cB = b[j - 1];
                dp[i][j] = INT_MAX;
                if(cA == cB){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                dp[i][j] = min({dp[i][j], 1 + dp[i - 1][j], 1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]});
            }
        }
        return dp[n][m];
    }
};