/*https://www.geeksforgeeks.org/count-number-subarrays-given-xor*/
-----------------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
----------------------------------------------------------------------------------
/*
	M2 : Hashmap Lookup
	O(n) time and O(n) space 
*/
	long long subarrayXor(int arr[], int n, int m)
	{
	    long long ans = 0;
	    int* xorArr = new int[n];
	    unordered_map<int, int> mp;
	    mp[0] ++;
	    xorArr[0] = arr[0];
	    for (int i = 1; i < n; i++)
	        xorArr[i] = xorArr[i - 1] ^ arr[i];
	    for (int i = 0; i < n; i++) {
	       	int tmp = m ^ xorArr[i];
	        ans = ans + ((long long)mp[tmp]);
	        mp[xorArr[i]]++;
	    }
	    return ans;
	}
----------------------------------------------------------------------------------