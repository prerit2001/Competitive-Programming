/*
https://leetcode.com/problems/min-cost-climbing-stairs/
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> v(cost.size(),0);
        for(int i=cost.size()-1;i>=0;i--){
        	if(i+2>=cost.size())v[i]=cost[i];
        	else v[i]=cost[i]+min(v[i+1],v[i+2]);
        }
        return min(v[0],v[1]);
    }
};