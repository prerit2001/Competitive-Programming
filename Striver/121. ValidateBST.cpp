/*https://leetcode.com/problems/validate-binary-search-tree/*/
/*
	M1: Range Recursion(BUT USE of IMPLICIT LONG LONG IS A NECESSITY)
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    bool isValidBST(TreeNode* root, ll mini = -1e15, ll maxi = 1e15) {
	        if(root == NULL){
	            return true;
	        }
	        if(root -> val > mini and root -> val < maxi){
	            if(isValidBST(root -> left, mini, root -> val)){
	                if(isValidBST(root -> right, root -> val, maxi)){
	                    return true;
	                }
	            }
	        } 
	        return false;
	    }
	};
/*
	M2: Inorder Traversal
	O(n) time and O(1) space

	If we use in-order traversal to serialize a binary search tree, we can
	get a list of values in ascending order. It can be proved with the
	definition of BST. And here I use the reference of TreeNode
	pointer prev as a global variable to mark the address of previous node in the
	list.
*/
	class Solution {
	public:
	    bool isValidBST(TreeNode* root) {
	        TreeNode* prev = NULL;
	        return validate(root, prev);
	    }
	    bool validate(TreeNode* node, TreeNode* &prev) {
	        if (node == NULL) return true;
	        if (!validate(node->left, prev)) return false;
	        if (prev != NULL && prev->val >= node->val) return false;
	        prev = node;
	        return validate(node->right, prev);
	    }
	};