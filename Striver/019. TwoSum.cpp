/*https://leetcode.com/problems/two-sum/*/
----------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
----------------------------------------------------------------------------
/*
	M2 : HashMap
	O(n or nlogn) time and O(n) space
*/
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];
			if (hash.find(numberToFind) != hash.end()) {
				result.push_back(hash[numberToFind] + 1);
				result.push_back(i + 1);			
				return result;
			}
			hash[numbers[i]] = i;
		}
		return result;
	}
----------------------------------------------------------------------------
/*
	M3: Two Pointers
	O(nlogn) time and O(n) aux space
*/
	class Solution {
	public:
	    vector<int> twoSum(vector<int>& nums, int target) {
	        int n = nums.size();
	        vector<pair<int, int>> arr(n);
	        for (int i = 0; i < n; ++i) {
	            arr[i] = make_pair(nums[i], i);
	        }
	        sort(arr.begin(), arr.end()); // Sort arr in increasing order by their values.
	        int left = 0, right = n- 1;
	        while (left < right) {
	            int sum2 = arr[left].first + arr[right].first;
	            if (sum2 == target) 
	                return {arr[left].second, arr[right].second};
	            if (sum2 > target)
	                right -= 1; // Try to decrease sum2
	            else
	                left += 1; // Try to increase sum2
	        }
	        return {};
	    }
	};
-----------------------------------------------------------------------------