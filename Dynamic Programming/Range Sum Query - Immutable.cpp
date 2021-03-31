/*
https://leetcode.com/problems/range-sum-query-immutable/
*/

class NumArray {
public:
    int pre_sum[10001];
    NumArray(vector<int>& nums) {
        memset(pre_sum,0,sizeof(pre_sum));
        pre_sum[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            pre_sum[i]+=pre_sum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right]-(left>0 ? pre_sum[left-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */