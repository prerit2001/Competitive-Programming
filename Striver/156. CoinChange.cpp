/*https://leetcode.com/problems/coin-change/*/
---------------------------------------------------------------
/*
	M1: Memo
	O(n*sum) time and O(n) space
*/
class Solution {
public:
    vector<int> a;
    int dp[10005];
    
    int go(int64_t curr, int64_t sum){
        if(curr == sum){
            return 0;
        }
        if(curr > sum){
            return 1e7;
        }
        if(dp[curr] != -1) return dp[curr];
        int ans = 1e6;
        for(auto it : a){
            ans = min(1 + go(curr+it,sum),ans);
        }
        return dp[curr] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        for(auto it : coins){
            if(it <= amount) a.push_back(it);
        }
        int ans = go(0,amount);
        return ans<1e5 ? ans : -1 ;
    }
};
---------------------------------------------------------------
/*
	M2: Tablulation
	O(n * sum) and O(n) space
*/
int dp[10005];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        dp[0] = 0;
        for(int i = 1; i <= amount; i ++){
            dp[i] = 1e7;
            for(int j = 0; j < coins.size(); j ++){
                if(i >= coins[j]){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if(dp[amount] > 1e5){
            return -1;
        }
        return dp[amount];
    }
};
---------------------------------------------------------------