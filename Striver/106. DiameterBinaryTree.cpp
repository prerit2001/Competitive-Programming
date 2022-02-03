/*https://leetcode.com/problems/diameter-of-binary-tree/*/
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
	int height(Node* root){
		if(root == NULL) return 0;
		return 1 + max(height(root -> left), height(root -> right));
	}
	int diameter(Node* root){
		if(root == NULL) return 0;
		int left_height = height(root -> left);
		int right_height = height(root -> right);
		int left_diameter = diameter(root -> left);
		int right_diameter = diameter(root -> right);
		return max({1 + left_height + right_height, left_diameter, right_diameter});
	}
/*
	M2 : Optimized
	O(n) time and O(1) space + O(n) recursion call stack
*/
	int ans = 0;
	int diameter(Node* root){
		if(root == NULL) return 0;
		int left_height = diameter(root -> left);
		int right_height = diameter(root -> right);
		ans = max(ans, 1 + left_height + right_height);
		return 1 + max(left_height, right_height);
	}

