// https://practice.geeksforgeeks.org/problems/edit-distance3702/1


class Solution {
  public:
    int dp[101][101];
    int go(int a, int b, string s, string t) {
        if(a == s.size() or b == t.size()){
            if(a == s.size() and b == t.size()) return 0;
            if(a != s.size()) return s.size() - a;
            if(b != t.size()) return t.size() - b;
        }
        if(dp[a][b] != -1) return dp[a][b];
        int ans = 1e5;
        if(s[a] == t[b]){
            int choice = go(a+1,b+1,s,t); // go ahead
            ans = min(ans,choice);
        }
        else{
            int choice1 = 1 + go(a,b+1,s,t); // insert
            int choice2 = 1 + go(a+1,b+1,s,t); // replace
            int choice3 = 1 + go(a+1,b,s,t); // remove
            ans = min({choice1,choice2,choice3});
        }
        return dp[a][b] = ans;
    }
    int editDistance(string s, string t) {
        memset(dp,-1,sizeof dp);
        int ans = go(0,0,s,t);
        return ans;
    }
};