/*https://practice.geeksforgeeks.org/problems/subset-sums2234/1#*/
--------------------------------------------------------------------------------------
/*
	M1: Recusive
	O(2^n) time and O(2^n) space
*/
	void subsetSums(int arr[], int l, int r, int sum = 0) {
	    // Print current subset
	    if (l > r) {
	        cout << sum << " ";
	        return;
	    }
	    // Subset including arr[l]
	    subsetSums(arr, l + 1, r, sum + arr[l]);
	    // Subset excluding arr[l]
	    subsetSums(arr, l + 1, r, sum);
	}
--------------------------------------------------------------------------------------
/*
	M2: Iterative Bitwise
	O(2^n * n) time and O(1) space
*/
	void subsetSums(int arr[], int n) {
	   	int total = 1 << n;
	    for (int i = 0; i < total; i++) {
	        int sum = 0;
	        for (int j = 0; j < n; j++)
	            if (i & (1 << j))
	                sum += arr[j];
	        cout << sum << " ";
	    }
	}
--------------------------------------------------------------------------------------