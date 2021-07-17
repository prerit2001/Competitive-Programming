// binary search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(right - left == 1){
                if(nums[left] < nums[right]) return right;
                else return left;
            }
            if(nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1]){
                return mid;
            }
            if(nums[mid] > nums[mid + 1]){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return left;
    }
};