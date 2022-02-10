/*https://leetcode.com/problems/flatten-binary-tree-to-linked-list/*/
/*
	M1: Recursive Backtrack
	O(n) time and O(n) Recur Call Stack Space 
*/
	class Solution {
    TreeNode* prev = NULL;
	public:
	    void flatten(TreeNode* root) {
	        if(root == NULL) return; 
	        
	        flatten(root->right); 
	        flatten(root->left); 
	        
	        root->right = prev;
	        root->left = NULL; 
	        prev = root; 
	    }
	};
/*
	M2: Iterative Optimatal (connect root -> left -> extreatme right -> right = root -> right, root = root -> right)
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    void flatten(TreeNode* root) {
	        TreeNode* cur = root;
			while (cur)
			{
				if(cur->left)
				{
					TreeNode* pre = cur->left;
					while(pre->right)
					{
						pre = pre->right;
					}
					pre->right = cur->right;
					cur->right = cur->left;
					cur->left = NULL;
				}
				cur = cur->right;
			}
	    }
	};