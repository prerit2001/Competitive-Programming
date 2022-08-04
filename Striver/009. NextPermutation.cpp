/*https://leetcode.com/problems/next-permutation/*/
------------------------------------------------------------------------------------
/*
	M1 : Brute force genrate all possible permutation
	O(n!) time and O(n) space
*/
------------------------------------------------------------------------------------
/*
	M2 : Single Pass Approach
	O(n) time and O(1) space
	
	Approach : 
		-> check if already in max permutation
		-> starting from last find first element which is not increasing
		-> swap this number which least greater number than this from right side
		-> reverse the right side of it

*/
	class Solution {
	public:
	    void nextPermutation(vector<int>& nums) {
	        int idx = -1;
	        int n = nums.size();
	        for(int i = n - 2; i >= 0; i --){
	            if(nums[i] < nums[i + 1]){
	                idx = i;
	                break;
	            }
	        }
	        if(idx == -1){
	            reverse(nums.begin(),nums.end());
	        }
	        else{
	            for(int i = n - 1; i >= 0; i --){
	                if(nums[idx] < nums[i]){
	                    swap(nums[idx],nums[i]);
	                    break;
	                }
	            }
	            reverse(nums.begin()+idx+1,nums.end());
	        }
	    }
	};
-----------------------------------------------------------------------------