/*https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/*/
-------------------------------------------------------------------------------------
/*
	M1: Always find the max feasible coin denomination
	O(K) time O(1) space
	K is the number of denomination 
*/
	int minCoins(int coins[], int m, int V) {
		int ans = 0;
		// coins are sorted in non increasing
		for(int i = 0; i < m; i ++){
			ans += V / coins[i];
			V %= coins[i];
		}
		return ans;
	}
-------------------------------------------------------------------------------------