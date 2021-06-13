// https://leetcode.com/problems/longest-palindromic-subsequence/

string s;
class Solution {
public:
    int dp[1005][1005];
    int go(int left, int right){
        if(left > right) return 0;
        if(left == right) return 1;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans = 0;
        if(s[left] == s[right]){
            ans = 2 + go(left+1,right-1);
        }
        else{
            ans = max(go(left+1,right),go(left,right-1));
        }
        return dp[left][right] = ans;
    }
    int longestPalindromeSubseq(string s) {
        ::s = s;
        memset(dp,-1,sizeof dp);
        return go(0,s.size()-1);
    }
};