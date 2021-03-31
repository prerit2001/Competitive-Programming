/*
https://leetcode.com/problems/min-cost-climbing-stairs/
*/

class Solution {
public:
	int dp[1001] = {};
	void go(vector<int>& cost,int curr){
		if(curr<0)return;
		if(curr+2>=cost.size()) dp[curr]=cost[curr];
		else dp[curr] = cost[curr]+min(dp[curr+1],dp[curr+2]);
		go(cost,curr-1);
	}
    int minCostClimbingStairs(vector<int>& cost) {
        go(cost,cost.size()-1);
        return min(dp[0],dp[1]);
    }
};