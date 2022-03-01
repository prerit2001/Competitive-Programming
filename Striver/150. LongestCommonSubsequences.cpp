/*https://leetcode.com/problems/longest-common-subsequence/*/
------------------------------------------------------------------
/*
	M1: Recursion
	O(2^n) time and O(2^n) rec space
*/
class Solution {
public:
	int lcs(int i, int n, int j, int m, string& s1, string& s2){
		if(i >= n or j >= n){
			return 0;
		}
		int chioce1 = 0;
		if(s1[i] == s2[j]){
			chioce1 = 1 + lcs(i + 1, n, j + 1, m, s1, s2);
		}
		int chioce2_a = lcs(i + 1, n, j, m, s1, s2);
		int chioce2_b = lcs(i, n, j + 1, m, s1, s2);

		return max({chioce1, chioce2_a, chioce2_b});
	}
	int longestCommonSubsequence(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		return lcs(0, n, 0, m, s1, s2);
	}
};
------------------------------------------------------------------
/*
	M2: Memoization
	O(n^2) time and O(n^2) space
*/

int dp[1000][1000]; // dp[i][j] = max len of common subsequence in s1 upto n - i and s2 upto n - j index
class Solution {
public:
	int lcs(int i, int n, int j, int m, string& s1, string& s2){
		if(i >= n or j >= n){
			return 0;
		}
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		int chioce1 = 0;
		if(s1[i] == s2[j]){
			chioce1 = 1 + lcs(i + 1, n, j + 1, m, s1, s2);
		}
		int chioce2_a = lcs(i + 1, n, j, m, s1, s2);
		int chioce2_b = lcs(i, n, j + 1, m, s1, s2);

		return dp[i][j] = max({chioce1, chioce2_a, chioce2_b});
	}
	int longestCommonSubsequence(string s1, string s2) {
        memset(dp, -1, sizeof dp);
		int n = s1.size(), m = s2.size();
		return lcs(0, n, 0, m, s1, s2);
	}
};
------------------------------------------------------------------
/*
	M3: Tabulation (Bottom Up)
	O(n^2) time and O(n^2) space
*/
int dp[1000][1000]; // dp[i][j] = max len of common subsequence in s1 upto i and s2 upto j index
class Solution {
public:
	int longestCommonSubsequence(string s1, string s2) {
        memset(dp, 0, sizeof dp);
		int n = s1.size(), m = s2.size();
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(s1[i] == s2[j]){
					dp[i][j] = 1 + ((i > 0 and j > 0) ? dp[i - 1][j - 1] : 0);
				}
				else{
					dp[i][j] = max({dp[i][j], (i > 0 ? dp[i - 1][j] : 0), (j > 0 ? dp[i][j - 1] : 0)});
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};
/*
	We can reduce the space complexity to linear as for any i we only care about i - 1
*/
------------------------------------------------------------------