/*https://leetcode.com/problems/palindromic-substrings/*/
------------------------------------------------------------------
/*
	M1: Memo
*/
------------------------------------------------------------------
/*
	M2: Tabulation
	O(n^2) time and O(n^2) space
*/
------------------------------------------------------------------
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i ++){
            dp[i][i] = 1;
        }
        int ans = n;
        for(int i = 2; i <= n; i ++){
            for(int j = i - 1; j < n; j ++){
                if(j - i + 2 <= j - 1){
                    if(dp[j - i + 2][j - 1] and s[j] == s[j - i + 1]){
                        dp[j - i + 1][j] = 1;                    
                        ans += 1;
                    }
                }
                else{
                    if(s[j] == s[j - i + 1]){
                        dp[j - i + 1][j] = 1;                    
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};
------------------------------------------------------------------
/*
	M3: Expand From Center
	O(n^2) time and O(1) space
*/
class Solution {
public:
    int countSubstrings(string s) {
        
        int n= s.length();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            
            // for odd length palindrome
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                
                ans++;
                l--;r++;
            }
            
            // for even length
            l=i;r=i+1;
            while(l>=0 && r<n&& s[l]==s[r]){
               
                ans++;
                l--;r++;
            }
            
            
        }
        return ans;
    }
};
------------------------------------------------------------------