/*https://leetcode.com/problems/symmetric-tree/*/
/*
	M1: Iterative level order traversal, check palindrome
	O(n) time and O(n) space
*/
/*
	M2: Recursion
	O(n) time and O(1) space
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true; //Tree is empty
        
        return isSymmetricTest(root->left,root->right);
    }
    
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //left & right node is NULL 
            return true; 
        
        else if(p == NULL || q == NULL) //one of them is Not NULL
            return false; 
        
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); //comparing left subtree's left child with right subtree's right child --AND-- comparing left subtree's right child with right subtree's left child
    }
};