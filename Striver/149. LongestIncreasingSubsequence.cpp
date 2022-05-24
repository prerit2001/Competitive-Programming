/*https://leetcode.com/problems/longest-increasing-subsequence/*/
---------------------------------------------------------------------------
/*
	M1: Recursion
	O(2^n) time and O(n) space
*/
class Solution {
public:
	int LIS(int cur, int n, vector<int>& nums, int prev = 0, bool started = 0){
		if(cur >= n){
			return 0;
		}
		int choice1 = 0;
		if(nums[cur] > prev or started == 0){
			choice1 = 1 + LIS(cur + 1, n, nums, nums[cur], 1);
		}
		int choice2 = 0 + LIS(cur + 1, n, nums, prev, started);
		return max(choice1, choice2);
	}
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		return LIS(0, n, nums);
	}
};
---------------------------------------------------------------------------
/*
	M2: Memoization (Top Down)
	O(n* max(a[i])) time and O(n* max(a[i])) space
*/
int dp[2500][10000][2];
class Solution {
public:
	int LIS(int cur, int n, vector<int>& nums, int prev = 0, bool started = 0){
		if(cur >= n){
			return 0;
		}
		if(dp[cur][prev][started] != -1){
			return dp[cur][prev][started];
		}
		int choice1 = 0;
		if(nums[cur] > prev or started == 0){
			choice1 = 1 + LIS(cur + 1, n, nums, nums[cur], 1);
		}
		int choice2 = 0 + LIS(cur + 1, n, nums, prev, started);
		return dp[cur][prev][started] = max(choice1, choice2);
	}
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		for(auto &it: nums) it += 1e4;
		memset(dp, -1, sizeof dp);
		return LIS(0, n, nums);
	}
}; 
/*
	To handle cases like negative numbers, add 1e4 to all elements before any operation
	To handle case like not using started variable, you can simply use prev as 0 and make sure no variable starts with 0 with above operation
	To Change Complexity from O(n*max(a[i])) to O(n^2), 
		-> just store all a[i] and have the predence value store in range 1 to n then do the same thing  
		-> do recursion like n^2   for x in range(i+1,len(nums)): if(nums[x]>nums[i]):
*/
---------------------------------------------------------------------------
/*
	M3: Tabulation (Bottom Up)
	O(n^2) time and O(n) space
*/
int dp[2505]; // max number of elements in LIS upto i index
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
    	int n = nums.size();
    	memset(dp, 0, sizeof dp);

    	for(int i = 0; i < n; i ++){
            dp[i] = 1;
    		for(int j = 0; j < i; j ++){
    			if(nums[j] < nums[i]){
    				dp[i] = max(dp[i], 1 + dp[j]);
    			}
    		}
    	}
    	
        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
---------------------------------------------------------------------------
/*
	M4: Binary Search
	O(nlogn) time and O(n) space
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
    	vector<int> lis; // stores LIS in sorted order
    	lis.reserve(n + 1);

    	for(int i = 0; i < n; i ++){
    		if(lis.size() == 0){
    			lis.push_back(nums[i]);
    		}
    		else{
    			// find the first index in lis greater than nums[i]

    			int low = 0, high = lis.size();
    			while(low < high){
    				int mid = (low + high) / 2;

    				if(lis[mid] >= nums[i]){
    					high = mid;
    				}
    				else{
    					low = mid + 1;
    				}

    			}

    			int index = low;
    			if(index == lis.size()){
    				lis.push_back(nums[i]);
    			}
    			else{
    				lis[index] = nums[i];
    			}

    		}
    	} 
    
        
    	return lis.size();
    }
};
---------------------------------------------------------------------------