/*
	M1 : Full Brute Force
	O(N^3) time and constant space

	Approach : 
		3 nested loops
*/
--------------------------------------------------------------------
/*
	M2 : Brute Force Optimal
	O(N^2) time constant space

	Approach : 
		2 nested loops
*/
--------------------------------------------------------------------
/*
	M3 : Kadane's Algorithm
	O(N) time and constant space

	Approach :
		take 2 variables -> max_so_far = 0, running_sum = 0
		for each in array :
			running_sum += a[i];
			if(running_sum < 0) running sum = 0;
			max_so_far = max(max_so_far, running_sum); 
*/
	int maxSubArray(vector<int> nums) {
     	int running_sum = 0, max_so_far = INT_MIN;
 		for(auto it : nums){
 			running_sum += it;
 			if(max_so_far < running_sum){
 				max_so_far = running_sum;
 			}
 			running_sum = max(0,running_sum);
 		}
 		return max_so_far;
    }
--------------------------------------------------------------