/*https://leetcode.com/problems/binary-search-tree-iterator/*/
/*
	M1: Store Inorder trasversal in vector and do Adhoc
	O(1) time per query and O(n) space
*/
/*
	M2: Tweak Morris Inorder Traversal
	O(1) Amortised time per query and O(h) stack space
*/
	class BSTIterator {
	public:
	    TreeNode* root;
	    stack<TreeNode*> s;
	    BSTIterator(TreeNode* root) {
	        this -> root = root;
	    }
	    
	    int next() {
	        TreeNode* elem;
	        if(root != NULL or s.size() > 0){
	            while(root != NULL){
	                s.push(root);
	                root = root -> left;
	            }
	            elem = s.top();
	            s.pop();
	            root = elem -> right;
	        }
	        return elem -> val;
	    }
	    
	    bool hasNext() {
	        if(root != NULL or s.size() > 0) return true;
	        else return false;
	    }
	};