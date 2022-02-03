/*https://leetcode.com/problems/maximum-width-of-binary-tree/*/
/*
	M1: O(n) time and O(n) steps
	steps:
		level order traversal
		ans = max(ans, size of queue for each level)
*/