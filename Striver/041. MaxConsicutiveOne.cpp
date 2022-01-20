/*https://leetcode.com/problems/max-consecutive-ones/*/
--------------------------------------------------------------------------------------
/*
	M1 : Ad - hoc traversal
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    int findMaxConsecutiveOnes(vector<int>& nums) {
	        int ans = 0;
	        int n = nums.size();
	        for(int i = 0; i < n; i ++){
	            if(nums[i] == 1){
	                int cnt = 0;
	                while(i < n and nums[i] == 1){
	                    i ++;
	                    cnt ++;
	                }
	                ans = max(cnt, ans);
	                i --;
	            }
	        }
	        return ans;
	    }
	};
--------------------------------------------------------------------------------------