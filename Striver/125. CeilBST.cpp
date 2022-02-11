/*https://www.codingninjas.com/codestudio/problems/920464*/
/*
	M1: Adhoc
	O(logn) time and O(1) space
*/
 	int findCeil(BinaryTreeNode<int> *root, int key){
		int ceil = -1; 
	    while (root) {

	        if (root->data == key) {
	            ceil = root->data;
	            return ceil;
	        }
	 
	        if (key > root->data) {
	            root = root->right;
	        }
	        else {
	            ceil = root->data; 
	            root = root->left;
	        }
	    }
	    return ceil; 
	}