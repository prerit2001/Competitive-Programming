/*https://leetcode.com/problems/subsets-ii/*/
--------------------------------------------------------------------------------------
/*
	M1: Recursion
	O(2^n * n) time and O(n) space
*/
	class Solution {
	public:
	    
	    void dfs(vector<int>& nums, int i, vector<int>& path, vector<vector<int>> & res, int n) {
	        res.push_back(path);
	        
	        if (i == n) {
	            return;
	        }
	        
	        for (int j = i; j < n; ++j) {
	            if (j != i && nums[j] == nums[j-1]) {
	                continue;
	            }
	            path.push_back(nums[j]);
	            dfs(nums, j + 1, path, res, n);
	            path.pop_back();
	        }
	    }
	    
	    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	        vector<vector<int>> res;
	        
	        int n = nums.size();
	        
	        if (n == 0) {
	            return res; 
	        }
	        
	        sort(nums.begin(),nums.end());
	        vector<int> path;
	        
	        dfs(nums, 0, path, res, n);
	        
	        return res; 
	    }
	};
--------------------------------------------------------------------------------------
/*
	M2: Iterative Bitwise and Simple Set
	O(2^n * n) time and O(2^n * n) space
*/
	class Solution {
	public:
	    vector<vector<int>> subsetsWithDup(vector<int>& nums){
	        set<vector<int>> s;
	        int n = nums.size();
	        for(int i = 0; i < (1 << n); i ++){
	            vector<int> curr;
	            for(int j = 0; j < n; j ++){
	                if((i >> (n - j - 1)) & 1){
	                    curr.push_back(nums[j]);
	                }
	            }
	            sort(nums.begin(),nums.end());
	            s.insert(curr);
	        }
	        vector<vector<int>>  v;
	        for(auto it : s) v.push_back(it);
	        return v;
	    }
	};
--------------------------------------------------------------------------------------
