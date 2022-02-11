/*https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457*/
/*
	M1: Adhoc
	O(logn) time O(1) space
*/
	int floorInBST(TreeNode<int> * root, int key)
	{
	    int floor = -1; 
	    while (root) {
	 
	        if (root->val == key) {
	            floor = root->val;
	            return floor;
	        }
	 
	        if (key > root->val) {
	            floor = root->val;
	            root = root->right;
	        }
	        else {
	            root = root->left;
	        }
	    }
	    return floor;
	}