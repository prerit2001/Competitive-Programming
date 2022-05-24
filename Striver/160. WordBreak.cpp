/*https://leetcode.com/problems/word-break/*/
-----------------------------------------------------------------------------
/*
	M1: Memo
	O(n ^ 3) time and O(n) space
*/
class Solution {
public:
    int dp[1005];
    int go(int curr, int n, string& s, map<string,bool>& mp){
        if(curr == n) return 1;
        if(dp[curr] != -1) return dp[curr];
        int ans = 0;
        string state = "";
        for(int i = curr; i < n; i ++){
            state += s[i];
            if(mp.count(state)){
                ans = max(ans,go(i+1,n,s,mp));
            }
        }
        return dp[curr] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> mp;
        for(auto &it : wordDict) mp[it] = 1;
        memset(dp,-1,sizeof dp);
        return go(0,s.size(),s,mp) ;   
    }
};
/*
	We can reduce time by changing map to trie by O(n^2)
*/
-----------------------------------------------------------------------------
/*
	M2: Tabulation
	O(n^3) time and O(n) space
*/
bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
-----------------------------------------------------------------------------