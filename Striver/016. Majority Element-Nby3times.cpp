/*https://leetcode.com/problems/majority-element-ii/*/
--------------------------------------------------------------------
/*
	M1: Brute Force Method
	O(n^2) time and O(1) space 
*/
---------------------------------------------------------------------
/*
	M2 : Frequencies Hash Method
	O(n or nlogn) time and O(n) space

	steps -> 
		1.build a map with key as element and value as its frequencies.
		2.traverse the map, and make sure to have running compution
		to have solution.
*/
----------------------------------------------------------------------
/*
	M3 : Sorting
	O(nlogn) time and O(1) space
*/
----------------------------------------------------------------------
/*
	M4 : Boyer Moore Voting Algorithm
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    vector<int> majorityElement(vector<int>& nums) {
	        int candidate1 = -1e9 - 1, candidate2 = -1e9 - 1;
	        int cnt1 = 0, cnt2 = 0;
	        for(int num : nums){
	            if(candidate1 == num){
	                cnt1 ++;
	            }
	            else if(candidate2 == num){
	                cnt2 ++;
	            }
	            else if(cnt1 == 0){
	                cnt1 = 1, candidate1 = num;
	            }
	            else if(cnt2 == 0){
	                cnt2 = 1, candidate2 = num;
	            }
	            else{
	                cnt1 -= 1, cnt2 -= 1;
	            }
	        }
	        vector<int> ans;
	        int CountCandidate1 = 0, CountCandidate2 = 0;
	        for(int num : nums){
	            if(num == candidate1) CountCandidate1 += 1;
	            if(num == candidate2) CountCandidate2 += 1;
	        }
	        if(CountCandidate1 > nums.size()/3){
	            ans.push_back(candidate1);
	        }
	        if(CountCandidate2 > nums.size()/3){
	            ans.push_back(candidate2);
	        }
	        return ans;
	    }
	};