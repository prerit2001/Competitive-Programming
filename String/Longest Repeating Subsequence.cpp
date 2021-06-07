// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

class Solution {
	public:
	    string s;
	    int dp[505][505];
	    int go(int curr1, int curr2, int n){
	        if(curr1 == n or curr2 == n) return 0;
	        if(dp[curr1][curr2] != -1) return dp[curr1][curr2];
	        int choice1 = 0;
	        if(s[curr2] == s[curr1]){
	            choice1 = 1 + go(curr1+1,curr2+1,n);
	        }
	        else{
	            choice1 = go(curr1,curr2+1,n);
	        }
	        int choice2 = 0;
	        if(curr1 == curr2 - 1){
	            choice2 = go(curr1+1,curr2+1,n);
	        }
	        else{
	            choice2 = go(curr1+1,curr2,n);
	        }
	        return dp[curr1][curr2] = max(choice1,choice2);
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    s = str;
		    for(int i=0;i<505;i++)
		    for(int j=0;j<505;j++)
		    dp[i][j] = -1;
		    int ans = go(0,1,s.size());
		    return ans;
		}
};