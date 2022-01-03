/*https://leetcode.com/problems/single-element-in-a-sorted-array/*/
--------------------------------------------------------------------------------------------
/*
    M1: Brute force
    O(n) time and O(1) space
    -> for every element check if another element adjecent to in is same or not linearly.
*/
--------------------------------------------------------------------------------------------
/*
    M2: Binary Search
    O(logn) time and O(1) space
*/
    class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            int left = 0, right = n;
            while(left < right){
                int mid = (left + right) >> 1;
                if(mid&1){
                    if(nums[mid] == nums[mid-1]){
                        left = mid + 1;
                    }
                    else{
                        right = mid;
                    }
                }
                else{
                    if(nums[mid] != nums[mid+1]){
                        right = mid;
                    }
                    else{
                        left = mid + 1;
                    }
                }
            }
            return nums[left];
        }
    };
--------------------------------------------------------------------------------------------
    