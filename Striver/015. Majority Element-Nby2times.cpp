/*https://leetcode.com/problems/majority-element/*/
---------------------------------------------------------------------
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
		2.traverse the map, and make sure to have max frequenciy element
		  stores in a variable while traversing the array.
*/
----------------------------------------------------------------------
/*
	M3 : Sorting
	O(nlogn) time and O(1) space
*/
----------------------------------------------------------------------
/*
	M4 : Randomisation
	O(50 * n or ∞) time and O(1) space

	steps ->
		1. while we will pick any random index as many times 
		as we do not come up with a solution.
		2. after picking an index we will traverse the array to
		check if it is the majority element by brute force manner.
		3. probablity that in the ith random index we do not found
		our majority elemnent is 1/(2^i).
		4. so in 50 steps 1/(2^50) ~ 000 approx.

*/
---------------------------------------------------------------------
/*
	M5 : Boyer Moore Voting Algorithm
	O(n) time and O(1) space
	
	steps ->
		1. divde the array into parts, such that in each part except
		last, the number of first element(considered as majority element
		of part) in the particular part will canceled out will all other 
		element of that part.
		2. first element of last part will be the answer because it is
		given that the majority element have > n/2 frequency. since last
		part sould not cancel all elements as usual as their previous parts.
*/
	class Solution {
	public:
	    int majorityElement(vector<int>& nums) {
	        int cnt = 0;
	        int candidate = 0;
	        for(int &num : nums){
	            if(cnt == 0){
	                candidate = num;
	            }
	            candidate == num ? cnt += 1 : cnt -= 1;   
	        }
	        return candidate;
	    }
	};