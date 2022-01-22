/*https://leetcode.com/problems/longest-palindromic-substring/*/
------------------------------------------------------------------------------------
/*
	M1: Brute Force(Genrate All Substring and Check Palindromicity)
	O(n^3) time and O(1) space
*/
------------------------------------------------------------------------------------
/*
	M2: Dynamic Programming
	O(n^2) time and O(n^2) space
*/
	int dp[1000][1000];
	int ans = 1;
	class Solution {
	public:
	    bool LPS(int p1, int p2, string& s){
	        if(p1 == p2){
	            dp[p1][p2] = 1;
	            return 1;
	        }
	        if(p1 > p2){
	            return 0;
	        }
	        if(dp[p1][p2] != -1){
	            return dp[p1][p2];
	        }
	        bool choice1 = 0, choice2 = 0, choice3 = 0;
	        LPS(p1 + 1, p2, s);
	        LPS(p1, p2 - 1, s);
	        if(s[p1] == s[p2]){
	            if(p1 + 1 == p2) {
	                dp[p1][p2] = 1;
	            }
	            else{
	                choice3 = LPS(p1 + 1, p2 - 1, s);
	                if(choice3 == 1){
	                    dp[p1][p2] = 1;
	                }
	            }
	        }
	        if(dp[p1][p2] != 1){
	            dp[p1][p2] = 0;
	        }
	        else{
	            ans = max(ans, p2 - p1 + 1);
	        }
	        return dp[p1][p2];
	    }
	    string longestPalindrome(string s) {
	        int n = s.size();
	        for(int i = 0; i < n; i ++){
	            for(int j = 0; j < n; j ++){
	                dp[i][j] = -1;
	            }
	        }
	        ans = 1;
	        LPS(0, n - 1, s);
	        for(int i = 0; i + ans - 1 < n; i ++){
	            if(dp[i][i + ans - 1] == 1){
	                return s.substr(i, ans);
	            }
	        }
	        return "";
	    }
	};
------------------------------------------------------------------------------------
/*
	M3: Expand Around Center
	O(n^2) time and O(1) space
*/
	String longestPalindrome(String s) {
	    if (s == null || s.length() < 1) return "";
	    int start = 0, end = 0;
	    for (int i = 0; i < s.length(); i++) {
	        int len1 = expandAroundCenter(s, i, i); // odd lenth
	        int len2 = expandAroundCenter(s, i, i + 1); // even lenth
	        int len = Math.max(len1, len2);
	        if (len > end - start) {
	            start = i - (len - 1) / 2;
	            end = i + len / 2;
	        }
	    }
	    return s.substring(start, end + 1);
	}

	int expandAroundCenter(String s, int left, int right) {
	    int L = left, R = right;
	    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
	        L--;
	        R++;
	    }
	    return R - L - 1;
	}
------------------------------------------------------------------------------------