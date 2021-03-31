/*
https://leetcode.com/problems/min-cost-climbing-stairs/
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size(),0);
        for(int i=cost.size()-1;i>=0;i--){
        	if(i+2>=cost.size())dp[i]=cost[i];
        	else dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};