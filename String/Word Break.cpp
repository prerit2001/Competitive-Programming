// https://practice.geeksforgeeks.org/problems/word-break1352/1#

int dp[1005];

int go(int curr, int n, string s, map<string,bool> mp){
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

int wordBreak(string A, vector<string> &B) {
    //code here
    map<string,bool> mp;
    for(auto &it : B) mp[it] = 1;
    memset(dp,-1,sizeof dp);
    return go(0,A.size(),A,mp) ;
}