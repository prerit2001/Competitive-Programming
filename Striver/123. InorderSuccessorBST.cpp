/*https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1*/
/*
	M1: Do a Inorder Travesal(store in vector -> vector is already sorted by defination)
	O(n) time and O(n) space
*/
/*
	M2: First Value Greater than k in inorder traversal is the answer
	O(n) time and O(1) space
*/
/*
	M3: Move right until k is bigger, then move left, reapeat
	O(logn) time and O(1) space
*/
	class Solution {
	public:
	    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	        TreeNode* successor = NULL;
	        
	        while (root != NULL) {
	            
	            if (p->val >= root->val) {
	                root = root->right;
	            } else {
	                successor = root;
	                root = root->left;
	            }
	        }
	        
	        return successor;
	    }
	};