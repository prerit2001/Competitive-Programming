/*https://leetcode.com/problems/product-of-array-except-self/*/
/*
	M1: brute force
	O(n^2) time and O(1) space
*/
/*
	M2: WITH DIVISION OPERATOR: multiply all and for each i devide it by a[i]
	O(n) time and O(1) space
*/
/*
	M3: WITHOUT DIVISION OPERATOR: build prefix and suffix array
	O(n) time and O(n) space
*/
/*
	M4: build prefix and suffix array in answer table to avoid using auxilary space
	O(n) time and O(1) space
*/