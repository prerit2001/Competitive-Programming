/*https://leetcode.com/problems/number-of-matching-subsequences/*/
-----------------------------------------------------------------------------
/*
	M1: Binary Search
	O(sum of len of words * logn) time and O(26*n) space
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> a[26];
        for(int i=0;i<s.size();i++){
            a[s[i]-'a'].push_back(i);
        }
        int cnt = 0;
        for(auto i : words){
            bool check = 1;
            int curr = 0;
            for(auto j : i){
                int up = lower_bound(a[j-'a'].begin(),a[j-'a'].end(),curr)-a[j-'a'].begin();
                if(up==a[j-'a'].size()){
                    check = 0;
                    break;
                }
                curr = a[j-'a'][up]+1;
            }
            if(check)
                cnt++;
        }
        return cnt;
    }
};
-----------------------------------------------------------------------------
/*
	M2: Suffix dp
	O(26*n + sum of len of words) time and O(26*n) space
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& word) {
        vector<vector<int>> dp(26,vector<int>(s.size(),s.size()));
        dp[s.back()-'a'][s.size()-1] = s.size() - 1; 
        for(int i = s.size() - 2; i >= 0; i --){
            for(int j = 0; j < 26; j ++){
                dp[j][i] = dp[j][i+1];
            }
            dp[s[i]-'a'][i] = i;
        }
        int cnt = 0;
        for(int i = 0; i < word.size(); i ++){
            int last = 0;
            for(int j = 0; j < word[i].size(); j ++){
                last = dp[word[i][j]-'a'][last];
                if(last >= s.size()) {
                    break;
                }
                if(j == word[i].size() - 1){
                    cnt ++;
                }          
                if(word[i][j] == word[i][j + 1]){
                	last ++;
                }
            }
        }
        return cnt;
    }
};
-----------------------------------------------------------------------------
