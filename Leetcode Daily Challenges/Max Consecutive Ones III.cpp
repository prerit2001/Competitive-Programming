// sliding window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = 0, cnt = 0;
        while(i < nums.size()){
            if(nums[i] == 0){
                cnt ++;
                nums[i] = -1;
            }
            if(cnt <= k){
                ans = max(i - j + 1, ans);   
            }
            else{
                while(cnt > k and j < nums.size()){
                    if(nums[j] == -1) cnt --;
                    j ++;
                }
            }
            i ++;
        }
        return ans;
    }
};