/*https://leetcode.com/problems/partition-equal-subset-sum/*/
-------------------------------------------------------------------------
/*
	M1: Memo
	O(n * sum) time and O(n * sum) space
*/
int dp[205][20005];
class Solution {
public:
    bool SST(int i, int n, vector<int>& nums, int need, int sum = 0){
        if(i >= n){
            return sum == need;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int choice1 = SST(i + 1, n, nums, need, sum + nums[i]);
        int choice2 = SST(i + 1, n, nums, need, sum);
        return dp[i][sum] = choice1 | choice2;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            total += nums[i];
        }
        if(total % 2 == 1){
            return false;
        }
        memset(dp, -1, sizeof dp);
        return SST(0, n, nums, total / 2);
    }
};
----------------------------------------------------------------------------
/*
	M2: Tabulation
	O(n*sum) time and O(sum) space
*/
bool dp[20005];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            total += nums[i];
        }
        if(total % 2 == 1){
            return false;
        }
        // we need to find subset sum (total / 2)
        total = total / 2;
        // now we need to find subset sum total
        for(int i = 0; i <= total; i ++){
            dp[i] = false;
        }
        for(int i = 0; i < n; i ++){
            for(int j = total; j >= 0; j --){
                if(dp[j] == true){
                    dp[j + nums[i]] = true; 
                }
            }
            dp[nums[i]] = 1;
        }
        return dp[total];
    }
};
----------------------------------------------------------------------------
/*
	M3: Bitset
	O((n * sum) / 64) time and O(sum) space
*/
#pragma GCC target("popcnt"); 
bitset<20005> bit;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            total += nums[i];
        }
        if(total % 2 == 1){
            return false;
        }
        bit.reset();
        bit[0] = 1;
        for(int i = 0; i < n; i ++){
            bit |= (bit << nums[i]);
        }
        return bit[total / 2];
    }
};
----------------------------------------------------------------------------