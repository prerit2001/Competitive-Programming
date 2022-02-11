/*https://leetcode.com/problems/kth-smallest-element-in-a-bst/solution/*/
/*
	M1: Store inorder and print its kth element
	O(n) time and O(n) space
*/
/*
	M2: Recursive Inorder and find kth elment without any storing
	O(n) time and O(1) space and O(h) call stack
*/
/*
	M3: Recursive Inorder and find kth elment without any storing
	O(n) time and O(1) space and O(h) stack
*/
	class Solution {
	  int kthSmallest(TreeNode root, int k) {
	    stack<int> stack;

	    while (true) {
	      while (root != null) {
	        stack.push(root);
	        root = root.left;
	      }
	      root = stack.pop();
	      if (--k == 0) return root.val;
	      root = root.right;
	    }
	  }
	}