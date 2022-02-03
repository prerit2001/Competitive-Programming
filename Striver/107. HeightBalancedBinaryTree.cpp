/*https://leetcode.com/problems/balanced-binary-tree/*/
/*
	M1: Optimal DFS
	O(n) time and O(1) space
*/
class Solution {
public:
    bool ok = 1;
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int leftH = height(root -> left);
        int rightH = height(root -> right);
        ok &= abs(leftH - rightH) <= 1;
        return 1 + max(leftH, rightH);
    }
    bool isBalanced(TreeNode* root) {
        ok = 1;
        height(root);
        return ok;
    }
};