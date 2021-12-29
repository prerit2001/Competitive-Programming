/*https://leetcode.com/problems/combination-sum-ii/*/
--------------------------------------------------------------------------------------
/*
	M2: Recursion
	O(2^n * n) time and O(n) space
*/
--------------------------------------------------------------------------------------
	#define ll long long
	class Solution {
	public:
	    void go(ll i, ll n, vector<int> &a, ll t, vector<vector<int>>& ans, vector<int> path){
	        if(t < 0) return;
	        if(i >= n){
	            if(t == 0) ans.push_back(path);
	            return;
	        }
	        ll nextIdx = n;
	        for(ll j = i; j < n; j ++){
	            if(a[i] != a[j]){
	                nextIdx = j;
	                break;
	            }
	        }
	        go(nextIdx, n, a, t, ans, path);
	        for(ll j = i; j < nextIdx; j ++){
	            path.push_back(a[j]);
	            go(nextIdx, n, a, t - a[i] * (j - i + 1), ans, path);
	        }
	    }
	    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
	        ll n = a.size();
	        vector<vector<int>> ans;
	        vector<int> path;
	        sort(a.begin(), a.end());
	        go(0, n, a, t, ans, path);
	        return ans;
	    }
	};
--------------------------------------------------------------------------------------