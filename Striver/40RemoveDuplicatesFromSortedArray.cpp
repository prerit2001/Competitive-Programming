/*https://leetcode.com/problems/remove-duplicates-from-sorted-array/*/
--------------------------------------------------------------------------------------
/*
	M1 : HashMap Lookup
	O(n) time and O(n) space
*/
--------------------------------------------------------------------------------------
/*
	M2 : Ad - hoc Traversal using two pointers
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    int removeDuplicates(vector<int>& nums) {
	        int k = 0;
	        int n = nums.size();
	        for(int i = 0; i < n; i ++){
	            int curr = nums[i];
	            while(i < n and nums[i] == curr){
	                i ++;
	            }
	            i --;
	            nums[k] = nums[i]; 
	            k ++;
	        }
	        return k;
	    }
	};
--------------------------------------------------------------------------------------
