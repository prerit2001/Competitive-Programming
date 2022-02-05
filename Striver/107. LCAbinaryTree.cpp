/*https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/*/
/*
    M1: Store Path then compare
    O(n) time and O(n) space

    eg: lca(3, 4) 
    path of 3 => 1,2,5,3
    path of 4 => 1,2,6,7,4
    1, 2 are common in both so 2 is the LCA
*/
/*
    M2: Optimised
    O(n) time and O(1) space
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
};