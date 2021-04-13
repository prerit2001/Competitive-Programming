/*
https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/
*/

class Solution {
public:
	std::vector<int> v;
    unordered_map<int,int> mp;
	int go(int curr,int k,int n){
		if(curr >= n){
			return 0;
		}
        if(mp.count(curr))return mp[curr];
		int maxi = 0;
		int sum = 0;
		for(int i=curr;i<curr+k and i<n;i++){
			maxi = max(maxi,v[i]);
			sum = max(sum,(i-curr+1)*maxi+go(i+1,k,n));
		}
        return mp[curr] = sum;
	}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        v = arr;
        return go(0,k,arr.size());
    }
};