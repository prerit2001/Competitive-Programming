/*https://leetcode.com/problems/trapping-rain-water/*/
-----------------------------------------------------------------------------------------
/*
	M2 : Brute Force
	O(n^2) time and O(1) space

	-> For each element in the array, we find the maximum level of water it can 
	trap after the rain, which is equal to the minimum of maximum height of bars 
	on both the sides minus its own height.
*/
-----------------------------------------------------------------------------------------
/*
	M2 : Dynamic Programming (Prefix and Suffix)
	O(n) time and O(n) space
*/
	int trap(vector<int>& height) {
	    if(height.empty()) return 0;
	    int ans = 0;
	    int size = height.size();
	    vector<int> left_max(size), right_max(size);
	    left_max[0] = height[0];
	    for (int i = 1; i < size; i++) {
	        left_max[i] = max(height[i], left_max[i - 1]);
	    }
	    right_max[size - 1] = height[size - 1];
	    for (int i = size - 2; i >= 0; i--) {
	        right_max[i] = max(height[i], right_max[i + 1]);
	    }
	    for (int i = 1; i < size - 1; i++) {
	        ans += min(left_max[i], right_max[i]) - height[i];
	    }
	    return ans;
	}
-----------------------------------------------------------------------------------------
/*
	M3 : Using Two Pointers
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    int trap(vector<int>& height) {
	        if (not height.size()) return 0;
	        int l = 0;
	        int r = height.size() - 1;
	        int left_max = 0, right_max = 0;
	        int ret = 0;
	            
	        while ( l < r ) {
	            if (height[l] < height[r]) {            // right will trap
	                left_max = max(left_max, height[l]);
	                ret += left_max - height[l];
	                l++;
	            }
	            else {                                  // left will trap
	                right_max = max(right_max, height[r]);
	                ret += right_max - height[r];
	                r--;
	            }
	        }
	        return ret;
	    }
	};
-----------------------------------------------------------------------------------------