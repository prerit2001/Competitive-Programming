/*https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/*/
/*
	M1: Define bound and Do Ad-hoc
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    int i;
	    Solution(){
	        i = 0;
	    }
	    TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {
	        if(i >= preorder.size()) return NULL;
	        if(preorder[i] > bound) return NULL;
	        TreeNode* node = new TreeNode(preorder[i ++]);
	        node -> left = bstFromPreorder(preorder, node -> val);
	        node -> right = bstFromPreorder(preorder, bound);
	        return node;
	    }
	};