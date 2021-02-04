/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n = a.size();
        if(a[0]>=target)return 1;
        int ans = n;
        for(int i=1;i<n;i++){
            if(a[i]>=target)return 1;
            a[i]+=a[i-1];
            if(a[i]<target)continue;
            int x = upper_bound(a.begin(),a.begin()+i-1,a[i]-target)-a.begin();
            ans = min(i-x+1,ans);
        }
        if(a[n-1]<target)return 0;
        return ans;
    }
};

/*
T.C : O(nlogn)
Auxilary Space : O(1)
*/