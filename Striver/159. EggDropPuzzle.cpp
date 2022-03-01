/*https://leetcode.com/problems/super-egg-drop*/
/*
	M1: Adhoc Memoization
	O(k * n ^ 2) time and O(n * k) space 
*/
int dp[105][10005];
class Solution {
public:
	int eggDropMemo(int k, int n){
		if(k == 1 or n <= 1){
			return n;
		}
		if(dp[k][n] != -1){
			return dp[k][n];
		}
		int ans = INT_MAX;
		for(int i = 1; i <= n; i ++){
			int choice1 = 1 + eggDropMemo(k - 1, i - 1);
			int choice2 = 1 + eggDropMemo(k, n - i);
			ans = min(ans, max(choice1, choice2)); // worst case senario
		}
		return dp[k][n] = ans;
	}
    int superEggDrop(int k, int n) {
    	memset(dp, -1, sizeof dp);
        return eggDropMemo(k, n);
    }
};
/*
	M2: Binary Search Memoization
	O(k * nlogn) time and O(n * k) space 
*/
int dp[105][10005];
class Solution {
public:
	pair<int, int> findCriticlePoint(int k, int n){
		int low = 1, high = n;
		while(low + 1 < high){
			int mid = (low + high) / 2;
			int belowCost = eggDropMemo(k - 1, mid - 1);
			int aboveCost = eggDropMemo(k, n - mid);
			if(belowCost < aboveCost){
				low = mid;
			}
			else if(belowCost > aboveCost){
				high = mid;
			}
            else{
                low = high = mid;
            }
		}
		return {low, high};
	}
	int eggDropMemo(int k, int n){
		if(k == 1 or n <= 1){
			return n;
		}
		if(dp[k][n] != -1){
			return dp[k][n];
		}
		pair<int, int> thresholdFloor = findCriticlePoint(k, n);
		
		int choice1 = 1 + max(eggDropMemo(k - 1, thresholdFloor.first - 1), eggDropMemo(k, n - thresholdFloor.first));
		int choice2 = 1 + max(eggDropMemo(k - 1, thresholdFloor.second - 1), eggDropMemo(k, n - thresholdFloor.second));
        
		return dp[k][n] = min(choice1, choice2);
	}
    int superEggDrop(int k, int n) {
    	memset(dp, -1, sizeof dp);
        return eggDropMemo(k, n);
    }
};
/*
	M3: Optimal Dynamic Programming
	O(n*k) time and O(n) space
*/
/*
	M4: Mathematical Binary Search
	O(k * logn) time and O(1) space
*/