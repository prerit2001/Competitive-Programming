// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#


class Solution{
    long long int dp[1005][1005];
    long long int mod = 1e9+7;
    public:
    string s;
    int go(int left, int right){
        if(left > right) return 0;
        if(left == right) return 1;
        if(dp[left][right] != -1) return dp[left][right]%mod;
        long long int ans = 0;
        if(s[left] == s[right]){
            ans = 1 + go(left+1,right)%mod + go(left,right-1)%mod;
            ans %= mod;
        }
        else{
            ans = go(left+1,right)%mod + go(left,right-1)%mod - go(left+1,right-1)%mod + mod;
            ans %= mod;
        }
        return dp[left][right] = ans%mod;
    }
    long long int  countPS(string str){
        s = str;
        memset(dp, -1, sizeof dp);
        return go(0,str.size()-1);
    }
     
};