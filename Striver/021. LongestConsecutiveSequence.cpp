/*https://leetcode.com/problems/longest-consecutive-sequence/*/
--------------------------------------------------------------------------------
/*
	M1 : Sort and Check
	O(nlogn) time and O(1) space
*/
--------------------------------------------------------------------------------
/*
	M2 : Hashmap Lookup
	O(n) time and O(n) space
*/
	class Solution {
	public:
	    int longestConsecutive(vector<int>& nums) {
	        int n = nums.size();
	        unordered_set<int> s;
	        for(auto &it : nums){
	            s.insert(it);
	        }
	        int ans = 0;
	        for(auto &it : s){
	            if(!s.count(it - 1)){
	                int len = 0;
	                int val = it;
	                while(s.count(val)){
	                	len ++;	
	                	val ++;
	                } 
	                ans = max(ans, len);
	            }
	        }
	        return ans;
	    }
	};