/*https://leetcode.com/problems/two-sum-iv-input-is-a-bst/*/
/*
	M1: HashSet Inorder Lookup or vector store lookup
	O(n) time and O(n) space
*/
/*
	M2: BST Iterator Class
	O(n) time and O(h) space

	have two different class Inorder and Revere Inorder with next iterator as functions and
	do the same as in two sum problem, left right compression
*/
class BST_Inorder {
public:
    TreeNode *root;
    stack<TreeNode*> s;
    BST_Inorder(TreeNode* root) {
        this -> root = root;
    }

    void next() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> left;
            }
            TreeNode* elem = s.top();
            s.pop();
            root = elem -> right;
        }
        else assert(0); // never happens
    }
    
   	TreeNode* getNext() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> left;
            }
            TreeNode* elem = s.top();
            return elem;
        }
        else{
        	return NULL;
        }
    }
};


class BST_Inorder_Reversed {
public:
    TreeNode *root;
    stack<TreeNode*> s;
    BST_Inorder_Reversed(TreeNode* root) {
        this -> root = root;
    }

    void next() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> right;
            }
            TreeNode* elem = s.top();
            s.pop();
            root = elem -> left;
        }
        else assert(0); // never happens
    }
    
   	TreeNode* getNext() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> right;
            }
            TreeNode* elem = s.top();
            return elem;
        }
        else{
        	return NULL;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BST_Inorder bstIn(root);
        BST_Inorder_Reversed bstInRev(root);
        while(bstIn.getNext() != NULL and bstInRev.getNext() != NULL){
            TreeNode* left = bstIn.getNext();
            TreeNode* right = bstInRev.getNext();
            if(left == right){
                break;
            }
            else if(left -> val + right -> val == k){
                return 1;
            }
            else if(left -> val + right -> val < k){
                bstIn.next();
            }
            else{
                bstInRev.next();
            }
        }
        return 0;
    }
};