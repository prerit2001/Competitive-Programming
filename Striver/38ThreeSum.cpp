/*https://leetcode.com/problems/3sum/*/
-----------------------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^3) time and O(1) space
*/
-----------------------------------------------------------------------------------------
/*
	M2 : Hashing
	O(n^2) time and O(n) space
*/
-----------------------------------------------------------------------------------------
/*
	M3 : Two Pointers
	O(n^2) time and O(1) space
*/
	class Solution {
	public:
	    vector<vector<int>> threeSum(vector<int>& a) {
	        sort(a.begin(), a.end());
	        int n = a.size();
	        vector<vector<int>> ans;
	        for(int i = 0; i < n; i ++){
	            if(i > 0 and a[i] == a[i - 1]) continue;
	            int sum = - a[i];
	            int left = i + 1, right = n - 1;
	            while(left < right){
	                int val = a[left] + a[right];
	                if(val == sum){
	                    ans.push_back({a[i], a[left], a[right]});
	                    int leftVal = a[left], rightVal = a[right];
	                    while(left < right and a[left] == leftVal) left ++;
	                    while(right > left and a[right] == rightVal) right --;
	                }
	                else if(val < sum){
	                    left ++;
	                }
	                else{
	                    right --;
	                }
	            }
	        }
	        return ans;
	    }
	};
-----------------------------------------------------------------------------------------