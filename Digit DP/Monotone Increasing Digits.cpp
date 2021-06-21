// https://leetcode.com/problems/monotone-increasing-digits/

class Solution {
public:
    int str_to_int(string temp){
        int ans = 0, prod = 1;
        while(temp.size()){
            ans += prod*(temp.back()-'0');
            temp.pop_back();
            if(prod == 1e9) break;
            prod *= 10;
        }
        return ans; 
    }
    
    string int_to_str(int temp){
        deque<char> d;
        while(temp){
            d.push_front(char((temp%10)+'0'));
            temp/=10;
        }
        string ans; 
        for(char c : d){
            ans += c;
        }
        return ans;
    }
    
    string s;
    int dp[10][2][10];
    string go(int curr, int n, bool tight, int last){
        if(curr == n){
            return "";
        }
        if(dp[curr][tight][last] != -1) return int_to_str(dp[curr][tight][last]);
        string ans = "";
        int ub = 9;
        if(tight == 1) ub = s[curr] - '0';
        for(int i = 0; i <= ub; i++){
            if( i >= last ){
                string c1 = char(i+'0') + go(curr+1,n,tight&(i==ub),i);
                string c2 = go(curr+1,n,tight,last);
                int choice1 = str_to_int(c1);
                int choice2 = str_to_int(c2);
                int cnt = str_to_int(ans);
                cnt = max({cnt,choice1,choice2});
                ans = int_to_str(cnt);
            }
        }
        dp[curr][tight][last] = str_to_int(ans);
        return ans;
    }
    int monotoneIncreasingDigits(int n) {
        while(n){
            s = char((n%10)+'0') + s;
            n/=10;
        }
        memset(dp, -1, sizeof dp);
        string ans = go(0,s.size(),1,0);
        return str_to_int(ans);
    }
};