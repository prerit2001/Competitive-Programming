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
	#include<bits/stdc++.h>
	using namespace std;

	float median(int num 1[],int num2[],int m,int n) {
	    if(m>n)
	        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array
	        
	    int low=0,high=m,medianPos=((m+n)+1)/2;
	    while(low<=high) {
	        int cut1 = (low+high)>>1;
	        int cut2 = medianPos - cut1;
	        
	        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
	        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
	        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
	        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
	        
	        if(l1<=r2 && l2<=r1) {
	            if((m+n)%2 != 0)
	                return max(l1,l2);
	            else 
	                return (max(l1,l2)+min(r1,r2))/2.0;
	        }
	        else if(l1>r2) high = cut1-1;
	        else low = cut1+1;
	    }
	    return 0.0;
	}

	int main() {
	    int nums1[] = {1,4,7,10,12};
	    int nums2[] = {2,3,6,15};
	    int m = sizeof(nums1)/sizeof(nums1[0]);
	    int n = sizeof(nums2)/sizeof(nums2[0]);
	    cout<<"The Median of two sorted arrays is"<<fixed<<setprecision(5)
	    <<median(nums1,nums2,m,n);
	    return 0;
	}
---------------------------------------------------------------------------------