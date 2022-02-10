/*https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723*/
/*
	M1: Ad-Hoc
	O(n) time and O(1) space
*/
	void changeTree(BinaryTreeNode < int > * root) {
	    if(root == NULL) return;
	    if(root -> left == NULL and root -> right == NULL) return;
	    int childsum = 0;
	  	if(root -> left != NULL) childsum += root -> left -> data;
	    if(root -> right != NULL) childsum += root -> right -> data;
	    int currentSum = root -> data;
	    if(childsum >= currentSum){
	        root -> data += childsum - currentSum;
	    }
	    else{
	       	if(root -> left != NULL) root -> left -> data += currentSum - childsum;
	        else root -> right -> data += currentSum - childsum;
	    }
	    
	    changeTree(root -> left);
	    changeTree(root -> right);
	    
	    childsum = 0;
	  	if(root -> left != NULL) childsum += root -> left -> data;
	    if(root -> right != NULL) childsum += root -> right -> data;
	    currentSum = root -> data;
	    if(childsum >= currentSum){
	        root -> data += childsum - currentSum;
	    }
	}  