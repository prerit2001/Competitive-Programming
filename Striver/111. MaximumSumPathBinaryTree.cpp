/*https://leetcode.com/problems/binary-tree-maximum-path-sum/*/
/*
	M1: Basic DFS handle all basic cases
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    int ans = -1001;
	    int dfs(TreeNode* root){
	        if(root == nullptr) return 0;
	        int leftMax = dfs(root -> left);
	        int rightMax = dfs(root -> right);
	        int val = max({root -> val, leftMax + root -> val, rightMax + root -> val});
	        ans = max({ans, val, leftMax + root -> val + rightMax});
	        return val;
	    }
	    int maxPathSum(TreeNode* root) {
	        ans = -1001;
	        dfs(root);
	        return ans;
	    }
	};