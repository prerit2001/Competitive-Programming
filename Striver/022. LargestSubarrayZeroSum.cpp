/*https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1*/
----------------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
----------------------------------------------------------------------------------
/*
	M2 : Hashmap Lookup
	O(n or nlogn) time and O(n) space
*/
int maxLen(vector<int>& arr, int n){
    unordered_map<int, int> presum;
    presum[0] = -1;

    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            presum[sum] = i;
        }
    }

    return max_len;
}
----------------------------------------------------------------------------------