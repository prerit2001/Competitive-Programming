// modified 2 - sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                for(int k = j + 1; k < n; k ++){
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];
                    int lb = lower_bound(nums.begin(),nums.end(),target - a - b - c) - nums.begin();
                    int ub = upper_bound(nums.begin(),nums.end(),target - a - b - c) - nums.begin();
                    int cnt = 0;
                    if(lb >= k + 1){
                        cnt = ub - lb;
                    }
                    else if(ub >= k + 1){
                        cnt = ub - k - 1;
                    }
                    if(cnt > 0){
                        vector<int> v = {a,b,c,target-a-b-c};
                        s.insert(v);
                    }
                }
            }
        }
        for(auto &it : s){
            ans.push_back(it);
        }
        return ans;
    }
};s