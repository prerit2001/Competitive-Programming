/*https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/*/
/*
	M1: dfs
	O(n) time and O(1) auxilary space
*/
class Solution {
public:
    TreeNode* constructTree(int left, int right, vector<int>& preorder, vector<int>& inorder, map<int, int>& mp, int& preid){
        if(left > right) return nullptr;
        int toAppend = preorder[preid];
        TreeNode* root = new TreeNode(toAppend);
        int index = mp[preorder[preid]];
        preid ++;
        root -> left = constructTree(left, index - 1, preorder, inorder, mp, preid);
        root -> right = constructTree(index + 1, right, preorder, inorder, mp, preid);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i ++){
            mp[inorder[i]] = i;
        }
        int preid = 0;
        TreeNode* root = constructTree(0, n - 1, preorder, inorder, mp, preid);
        return root;
    }
};