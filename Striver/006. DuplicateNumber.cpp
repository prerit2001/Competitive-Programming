/*https://leetcode.com/problems/find-the-duplicate-number/*/
-------------------------------------------------------------------
/*
	M1 : Brute force 
	O(n^2) time and O(1) space
*/
-------------------------------------------------------------------
/*
	M2 : Hashmap 
	O(n) time and O(n) space
*/
-------------------------------------------------------------------
/*
	M3 : Negative Index Approach
	O(n) time and O(1) space
*/
	int findDuplicate(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i ++){
            if(a[abs(a[i]) - 1] > 0){
                a[abs(a[i]) - 1] *= -1;
            }
            else{
                return abs(a[i]);
            }
        }
        return 0;
    }
-------------------------------------------------------------------
/*
    M4: Without Modifying Array -> read linked list cycle start point
    O(n) time and O(1) space
*/
    class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            while (nums[0] != nums[nums[0]])
                swap(nums[0], nums[nums[0]]);
            return nums[0];
    };
--------------------------------------------------------------------