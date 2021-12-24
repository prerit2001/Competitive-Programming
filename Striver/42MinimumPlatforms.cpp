/*https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#*/
-----------------------------------------------------------------------------------
/*
	M1: Arrival Departure Prefix sum
	O(n) time and O(constant value) space 
*/
	int minPlatform(int arrival[], int departure[], int n){
	    int platform[2361] = {0};
	    int requiredPlatform = 1;
	    for (int i = 0; i < n; i++) {
	        ++platform[arrival[i]]; 
	        --platform[departure[i] + 1];
	    }
	    for (int i = 1; i < 2361; i++) {
	        platform[i] = platform[i] + platform[i - 1]; 
	        requiredPlatform = max(requiredPlatform, platform[i]);
	    }
	    return requiredPlatform;
	}
-----------------------------------------------------------------------------------