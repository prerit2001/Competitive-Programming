/*
https://leetcode.com/problems/climbing-stairs/
*/

class Solution {
public:
	int dp[46] = {};
	int go(int curr,int n){
		if(curr > n)return 0;
		if(dp[curr]!=-1)return dp[curr];
		if(curr==n)return 1;
		return dp[curr] = go(curr+1,n)+go(curr+2,n);
	}
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return go(0,n);
    }
};