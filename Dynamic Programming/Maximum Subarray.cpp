/*
https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     	int curr = 0, max_so_far = INT_MIN;   
     	bool all_negative = true;
     	for(auto it : nums)
     		if(it>0){
     			all_negative = false;
     			break;
     		}
 		if(all_negative){
 			return *max_element(nums.begin(), nums.end());
 		}
 		for(auto it : nums){
 			curr += it;
 			if(max_so_far < curr){
 				max_so_far = curr;
 			}
 			curr = max(0,curr);
 		}
 		return max_so_far;
    }
};