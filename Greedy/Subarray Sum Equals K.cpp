// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n);
        pre[0] = a[0];
        for(int i = 1; i < n; i ++){
            pre[i] += pre[i-1] + a[i]; 
        }
        int sum = 0;
        map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i ++){
            if(mp.count(pre[i]-k)) sum += mp[pre[i]-k];
            mp[pre[i]] ++;
        }
        return sum ;
    }
};