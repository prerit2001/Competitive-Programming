/*https://leetcode.com/problems/search-in-a-binary-search-tree/*/
/*
	M1: Recursive
	O(logn) time and O(h) recursion call stack, (optimal if implicit call stack is not considered)
*/
	class Solution {
	public:
	    TreeNode* searchBST(TreeNode* root, int val) {
	        if(!root) return root;
	        TreeNode *node=new TreeNode(); 
	        if(val<root->val){
	            node=searchBST(root->left,val);
	        } else if(val>root->val){
	            node=searchBST(root->right,val);
	        } else {
	            node=root;
	        }
	        return node;
	    }
	};
/*
	M2: Iterative
	O(logn) time and O(1) space 
*/
	TreeNode* searchBST(TreeNode* root, int val) {
	    while (root != nullptr && root->val != val) {
	      root = (root->val > val) ? root->left : root->right;
	    }
	    return root;
	}
	