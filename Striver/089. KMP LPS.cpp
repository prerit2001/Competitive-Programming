/*https://leetcode.com/problems/implement-strstr/submissions/*/
----------------------------------------------------------------
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0;
        vector<int> lps = LPS(needle+"$"+haystack);
        for(int i = 1; i < lps.size(); i ++){
            if(lps[i] == n) return i - 2 * needle.size();
        } 
        return -1;
    }
    vector<int> LPS(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
--------------------------------------------------------------------
/*

Difference between LPS KMP and Z-function


// Longest Prefix Suffix KMP -> 

	lps[i] = k means => { s.substring(0 to k) == s.substring(i - k + 1, i) }
	Eg -> {
		string s = abcabcd

		lps[0] = 0; XXXX 0 index didn't consider
		lps[1] = 0;
		lps[2] = 0;
		lps[3] = 1; // s[0...0] == s[3...3]  -> { s[i...j] = substring of s from i to j inclusive. }
		lps[4] = 2; // s[0...1] == s[3...4]
		lps[5] = 3; // s[0...2] == s[3...5]
		lps[6] = 0; 

	}


// Z-function -> 

	z[i] = k means => {s.substring(0, k) == s.substring(i, i + k - 1)} 
	Eg -> {
		string s = abcabcd

		z[0] = 0; XXXX 0 index didn't consider
		z[1] = 0;
		z[2] = 0;
		z[3] = 3; // s[0...2] == s[3...5]
		z[4] = 0;
		z[5] = 0; 
		z[6] = 0; 

	}
	
*/