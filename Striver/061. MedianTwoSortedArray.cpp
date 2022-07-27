/*https://leetcode.com/problems/median-of-two-sorted-arrays/*/
---------------------------------------------------------------------------------
/*
	M1: Merge the two arrays and then find the median
	O(n1 + n2) time and O(n1 + n2) space
*/
----------------------------------------------------------------------------------
/*
	M2: Take two pointers, one starting at first index of first array and the
		other starting at the first index of second array, just traverse smartly
	O(n1 + n2) time and O(1) spaces
*/
----------------------------------------------------------------------------------
/*
	M3: Advance Binary Search
	O(log(n1 + n2)) time and O(1) space

	https://www.youtube.com/watch?v=ws98ud9uxl4

	Approach :

	We will do a binary search in one of the arrays which have a minimum size among the two. 

	Firstly, calculate the median position with (n+1)/2. 
	Point two-pointer, say low and high, equal to 0 and size of the array on which we 
	are applying binary search respectively. Find the partition of the array. 
	Check if the left half has a total number of elements equal to the median position. 
	If not, get the remaining elements from the second array. Now, check if partitioning is valid. 
	This is only when l1<=r2 and l2<=r1. If valid, return max(l1,l2)(when odd number 
	of elements present) else return (max(l1,l2)+min(r1,r2))/2.

	If partitioning is not valid, move ranges. When l1>r2, move left and perform the 
	above operations again. When l2>r2, move right and perform the above operations.
*/
	class Solution {
	public:
	    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	        
	        int n = nums1.size();
	        int m = nums2.size();
	        
	        // nums1 len < nums2 len 
	        if(n > m){
	            return findMedianSortedArrays(nums2, nums1);
	        }
	        
	        int low1 = 0, high1 = n;
	        int medianId = (n + m + 1) / 2;
	        while(low1 <= high1){
	            
	            int mid1 = low1 + (high1 - low1) / 2; // avoid overflow -> corner case
	            int mid2 = medianId - mid1;
	            
	            int max1 = mid1 == n ? INT_MAX: nums1[mid1];
	            int min1 = mid1 == 0 ? INT_MIN: nums1[mid1 - 1];
	            
	            int max2 = mid2 == m ? INT_MAX: nums2[mid2];
	            int min2 = mid2 == 0 ? INT_MIN: nums2[mid2 - 1];
	            
	            if(max1 >= min2 and max2 >= min1){
	                if((n + m) % 2 == 0){
	                    return (max(min1, min2) + min(max1, max2)) / 2.0;
	                }
	                else{
	                    return max(min1, min2);
	                }
	            }
	            else if(max1 < min2){
	                low1 = mid1 + 1;
	            }
	            else{
	                high1 = mid1 - 1;
	            }
	            
	        }
	         
	        assert(0); // not possible for code to react this line, but if code exactly reached this line that means there is some logical error in code;
	        return -1;
	        
	    }
	};
---------------------------------------------------------------------------------