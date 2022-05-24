/*https://leetcode.com/problems/palindrome-partitioning/*/
---------------------------------------------------------------
/*
	M1: Bit Manipulation
	O(n*2^n) time and O(n*2^n) space
*/
#define ll long long
class Solution {
public:
    bool isPalindrome(string s){
        for(ll i = 0; i < s.size() / 2; i ++) {
            if(s[i] != s[s.size() - 1 - i])
                return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        ll n = s.size();
        vector<vector<string>> ans;
        for(ll i = 1; i < (1LL << n); i ++){
            bool flag = 1;
            vector<string> K;
            string m = "";
            for(ll j = 0; j < n; j ++){
                if(1 & (i >> j)){
                    m += s[j];
                    if(!isPalindrome(m)) flag &= 0;
                    K.push_back(m);
                    m = "";
                }
                else{
                    m += s[j];
                    if(j == n - 1) {
                        if(!isPalindrome(m)) flag &= 0;
                        K.push_back(m);
                    }
                }
            }
            if(flag) 
                ans.push_back(K);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
---------------------------------------------------------------
/*
	M2: Dynamic Programming
*/

 |
 |
\|/
