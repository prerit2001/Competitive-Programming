// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool dp[2001][2001];
    bool vis[2001][2001];
    string s1,s2;
    int last_occurance_of_some_character = -1;
    bool go(int curr1, int curr2){
        
        if(curr2 == s2.size()) return curr1 > last_occurance_of_some_character;
        if(curr1 == s1.size()) return false;
        
        if(vis[curr1][curr2]) return dp[curr1][curr2];
        vis[curr1][curr2] = 1;
        
        if(s1[curr1] == '?'){
            return dp[curr1][curr2] = go(curr1+1,curr2+1);   
        }
        if(s1[curr1] == '*'){
            return dp[curr1][curr2] = (go(curr1,curr2+1) or go(curr1+1,curr2));
        }
        if(s1[curr1] == s2[curr2]){
            return dp[curr1][curr2] = go(curr1+1,curr2+1);
        }
        else return dp[curr1][curr2] = false;
    
    }
    bool isMatch(string s, string p) {
        s1 = p, s2 = s;
        memset(vis, 0, sizeof vis);
        for(int i=0;i<p.size();i++){
            if(p[i]!='*'){
                last_occurance_of_some_character = i;
            }
        }
        return go(0,0);
    }
};