/*https://leetcode.com/problems/search-in-rotated-sorted-array/*/
-----------------------------------------------------------------------
/*
	M1: Brute Force
	O(n) time and O(1) space
	-> check if next element is smaller than privious one linerly
*/
-----------------------------------------------------------------------
/*
	M2: Binary Search
	O(logn) time and O(1) space
*/
	class Solution {
	public:
	    int search(vector<int>& a, int target) {
	        int low = 0, high = a.size() - 1; 
	        while(low <= high) {
	            int mid = (low + high) >> 1; 
	            if(a[mid] == target) return mid; 
	            
	            // the left side is sorted
	            if(a[low] <= a[mid]) {
	                if(target >= a[low] && target <= a[mid]) {
	                    high = mid - 1; 
	                }
	                else {
	                    low = mid + 1; 
	                }
	            }
	            else {
	                if(target >= a[mid] && target <= a[high]) {
	                    low = mid + 1; 
	                }
	                else {
	                    high = mid - 1; 
	                }
	            }
	        } 
	        return -1; 
	    }
	};
-----------------------------------------------------------------------