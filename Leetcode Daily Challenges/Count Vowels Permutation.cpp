int mod = 1e9 + 7;
int dp[20005][256];
class Solution {
public:
    long go(int curr, int n, char prev){
        if(curr == n) return 1;
        if(dp[curr][prev] != -1) return dp[curr][prev];
        long ans = 0;
        for(char c : {'a','e','i','o','u'}){
            if(curr != 0){
                if(c == 'a' and prev == 'e'){
                    ( ans += go(curr + 1, n, c)% mod ) % mod;
                }
                else if(c == 'e' and (prev == 'a' or prev == 'i')){
                    ( ans += go(curr + 1, n, c)% mod ) % mod;
                }
                else if(c == 'i' and prev != 'i'){
                    ( ans += go(curr + 1, n, c)% mod ) % mod;
                }
                else if(c == 'o' and (prev == 'i' or prev == 'u')){
                    ( ans += go(curr + 1, n, c)% mod ) % mod;
                }
                else if(c == 'u' and prev == 'a'){
                    ( ans += go(curr + 1, n, c)% mod ) % mod;
                }
            }
            else{
                ( ans += go(curr + 1, n, c)% mod ) % mod;
            }
        }
        return dp[curr][prev] = ans % mod;
    }
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof dp);
        return (int)go(0,n,'a');
    }
};