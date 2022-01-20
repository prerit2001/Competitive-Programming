/*https://leetcode.com/problems/longest-substring-without-repeating-characters/*/
----------------------------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
----------------------------------------------------------------------------------------------
/*
	M2 : Sliding Window Compression
	O(2*n) time and O(n or 256) space 
*/
	class Solution {
	public:
	    int lengthOfLongestSubstring(string s) {
	        unordered_map<char, int> lookup;
	        int maxLen = 0, left = 0, right = 0;
	        int n = s.size();
	        while(right < n){
	        	while(left <= right and lookup.count(s[right]) and lookup[s[right]] >= left){
	        		left ++;
	        	}
                lookup[s[right]] = right;
	        	maxLen = max(maxLen, right - left + 1);
                right ++;
	        }
	        return maxLen;
	    }
	};
----------------------------------------------------------------------------------------------
/*
	M3 : Hasmap Lookup
	O(n) time and O(n or 256) space 
*/
	class Solution {
	public:
	    int lengthOfLongestSubstring(string s) {
	        unordered_map<char, int> lookup;
	        int maxLen = 0, left = -1;
	        for (int right = 0; right < s.size(); right ++) {
	            if(lookup.count(s[right])){
	                left = max(left, lookup[s[right]]);
	            }
	            lookup[s[right]] = right;
	            maxLen = max(maxLen, right - left);
	        }
	        return maxLen;
	    }
	};
----------------------------------------------------------------------------------------------