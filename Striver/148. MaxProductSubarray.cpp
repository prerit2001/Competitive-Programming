/*https://leetcode.com/problems/maximum-product-subarray/*/
-----------------------------------------------------------------
/*
	M1: Brute Force
	O(n^3) time and O(1) space 
*/
int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}
-----------------------------------------------------------------
/*
	M2: Better
	O(n^2) time and O(1) space
*/
int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}
------------------------------------------------------------------
/*
	M3: Optimal
	O(n) time and O(1) space
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i ++){
            int p1 = maxProd * nums[i];
            int p2 = minProd * nums[i];
            maxProd = max({nums[i], p1, p2});
            minProd = min({nums[i], p1, p2});
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
-------------------------------------------------------------------