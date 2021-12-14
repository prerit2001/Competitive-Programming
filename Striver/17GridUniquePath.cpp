/*https://leetcode.com/problems/unique-paths/*/
--------------------------------------------------------------------------
/*
	M1 : Dynamic Programing Choice Diagramme
	O(n * m) time and O(n * m) space
*/
	class Solution {
	public:
	    vector<vector<int>> dp;
	    int possible(int i, int j, int n, int m){
	        return i >= 0 and j >= 0 and i < n and j < m;
	    }
	    int dfs(int i, int j, int n, int m){
	        if(!possible(i, j, n, m)) return 0;
	        if(i == n - 1 and j == m - 1) return 1;
	        if(dp[i][j] != -1) return dp[i][j];
	        int choice1 = dfs(i + 1, j, n, m);
	        int choice2 = dfs(i, j + 1, n, m);
	        return dp[i][j] = choice1 + choice2;
	    }
	    int uniquePaths(int m, int n) {
	        dp.resize(m, vector<int>(n, -1));
	        return dfs(0, 0, m, n);
	    }
	};
--------------------------------------------------------------------------
/* 
	M2 : Combinatorics
	O(min(m, n)) time and O(1) space

	steps ->
		1. 1,1 to n,m
		2. numbers of right turn should be m - 1 exactly.
		3. numbers of down turn should be n - 1 excatly.
		4. totals moves should me m - 1 + n - 1 excatly.
		5. answer should be (totals)C(down) or (totals)C(right) 
*/
	class Solution {
	public:
	    int nCr(int n, int r){
	        double x = 1;
	        if(r > n - r) r = n - r;
	        for(int i = 0; i < r; i ++){
	            x *= (n - i);
	            x /= i + 1;
	        }
	        return x;
	    }
	    int uniquePaths(int m, int n) {
	        int r = n - 1;
	        int d = m - 1;
	        int tot = r + d;
	        return nCr(tot, d);
	    }
	};
--------------------------------------------------------------------------