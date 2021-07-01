/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int timer = 0;
map<TreeNode*,int> starttime, endtime;
map<TreeNode*,bool> vis;         
map<TreeNode*,TreeNode*> adj;
class Solution {
public:
    void dfs(TreeNode* root){
        timer++;
        starttime[root] = timer;
        vis[root] = 1;
        
        if(root -> left != NULL and !vis.count(root -> left)){
            adj[root -> left] = (root);
            dfs(root -> left);
        }
        if(root -> right != NULL and !vis.count(root -> right)){
            adj[root -> right] = (root);
            dfs(root -> right);
        }
        
        timer++;
        endtime[root] = timer;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        while(p != q){
            if(starttime[p] < starttime[q] and endtime[p] > endtime[q]){
                // q is in subtree of p
                q = adj[q];
            }
            else if(starttime[p] > starttime[q] and endtime[p] < endtime[q]){
                // p is in subtree of q
                p = adj[p];
            }
            else{
                // both are in differnet branches of binary tree
                p = adj[p];
                q = adj[q];
            }
        }
        return p;
    }
};