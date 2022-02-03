/*https://leetcode.com/problems/maximum-depth-of-binary-tree/*/
/*
	M1: Using LEVEL ORDER TRAVERSAL
	O(n) time and O(n) space

	steps: 
	If we observe carefully, the depth of the Binary Tree is the number of levels in the 
	binary tree. So, if we simply do a level order traversal on the binary tree and keep
	 a count of the number of levels, it will be our answer.
*/
/*
	M2: DFS Recursively ( Post Order Traversal )
	O(n) time and O(1) space
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};