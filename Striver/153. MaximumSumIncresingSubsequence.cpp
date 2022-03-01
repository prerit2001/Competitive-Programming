/*https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#*/
------------------------------------------------------------------------------------------
/*
	M1: Memo
	O(n^2) time and O(n) space
*/
class Solution{
	public:
	int MSIS(int i, int arr[], int n, vector<int>& dp){
	    if(i >= n){
	        return 0;
	    }
	    if(dp[i] != -1){
	        return dp[i];
	    }
	    int ans = 0;
	    for(int j = i + 1; j < n; j ++){
	        if(arr[j] > arr[i]){
	            ans = max(ans, arr[i] + MSIS(j, arr, n, dp));
	        }
	    }
	    ans = max(ans, arr[i] + MSIS(n, arr, n, dp));
	    return dp[i] = ans;
	}
	int maxSumIS(int arr[], int n){  
	    vector<int> dp(n, -1);
	    int ans = 0;
	    for(int i = 0; i < n; i ++){
	        if(dp[i] == -1){
	            ans = max(ans, MSIS(i, arr, n, dp));
	        }
	    }
	    return ans;
	}  
};
------------------------------------------------------------------------------------------
/*
	M2: Tabulation
	O(n^2) time and O(n) space
*/
class Solution{
	public:
	int maxSumIS(int arr[], int n){  
	    int dp[n + 1];
	    dp[0] = 0;
	    for(int i = 1; i <= n; i ++){
	        dp[i] = arr[i - 1];
	        for(int j = 1; j < i; j ++){
	            if(arr[j - 1] < arr[i - 1]){
	                dp[i] = max(dp[i], arr[i - 1] + dp[j]);
	            }
	        }
	    }
	    int ans = 0;
	    for(int i = 1; i <= n; i ++){
	        ans = max(ans, dp[i]);
	    }
	    return ans;
	}  
};
------------------------------------------------------------------------------------------