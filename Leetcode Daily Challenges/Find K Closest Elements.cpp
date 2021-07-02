class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size();
        int idx = 0;
        for(int i = 0; i < n; i ++){
            if(abs(a[i] - x) < abs(a[idx] - x)){
                idx = i;
            }
        }
        vector<int> ans;
        ans.push_back(a[idx]);
        k --;
        int left = idx - 1, right = idx + 1;
        while(k-- > 0){
            if(left >= 0 and right < n){
                if(abs(a[right] - x) < abs(a[left] - x)){
                    ans.push_back(a[right]);
                    right ++;
                }
                else{
                    ans.push_back(a[left]);
                    left --;
                }
            }
            else if(left >= 0){
                ans.push_back(a[left]);
                left --;
            }
            else if(right < n){
                ans.push_back(a[right]);
                right ++;
            }
            else{
                // not possible
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};