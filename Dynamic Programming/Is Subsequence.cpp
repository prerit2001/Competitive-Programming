/*
https://leetcode.com/problems/is-subsequence/
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
     	int s_ind = 0;
     	bool ok = true;
     	for(auto it : t){
     		if(it == s[s_ind])s_ind++;
     	} 
     	return (ok = (s_ind>=s.size() ? true : false));  
    }
};