/*https://leetcode.com/problems/first-missing-positive/*/
-----------------------------------------------------------------------
/*
	BEST METHOD : USE INDEX AS A HASH
	O(n) time and O(1) space
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        nums.push_back(0);
        for(auto &it: nums){
            if(it <= 0 or it > n + 1){
                it = n + 2;
            }
        }
        // ans range (1 - n + 1)
        for(auto &it: nums){
            if(abs(it) > 0 and abs(it) <= n + 1) {
                nums[abs(it)] = -abs(nums[abs(it)]);
            }
        }
        for(int i = 1; i <= n + 1; i ++){
            if(nums[i] >= 0) return i;
        }
        return -1;
    }
};
-----------------------------------------------------------------------