/*https://leetcode.com/problems/longest-valid-parentheses/*/
-------------------------------------------------------------
/*
	M1: Brute Force
	O(n^3) or O(n^2) time and O(n) space 
*/
-------------------------------------------------------------
/*
	M2: DP
	O(n) time and O(n) space
	
	dp[i] = lenth of valid string ending at i
	
	if si == ( then dpi = 0
	if si == ) and si-1 == ( then dpi = 2 + dp[i - 2]
	if si == ) and si-1 == ) then 
		if s[i - dp[i - 1]] == ( then dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 1];
		else dpi = 0
*/
	class Solution {
	public:
	    int longestValidParentheses(string s) {
	        int n = s.size();
	        vector<int> dp(n);
	        int ans = 0;
	        for(int i = 0; i < n; i ++){
	            if(s[i] == '('){
	                dp[i] = 0;
	            }
	            else{
	                if(i - 1 >= 0 and s[i - 1] == '('){
	                    dp[i] = 2;
	                    if(i - 2 >= 0) dp[i] += dp[i - 2];
	                }
	                else if(i - 1 >= 0 and s[i - 1] == ')'){
	                    if(i - 1 - dp[i - 1] >= 0 and s[i - 1 - dp[i - 1]] == '('){
	                        dp[i] = dp[i - 1] + 2;
	                        if(i - 1 - dp[i - 1] - 1 >= 0){
	                            dp[i] += dp[i - 1 - dp[i - 1] - 1];
	                        }
	                    }
	                }
	            }
	            ans = max(ans, dp[i]);
	        }
	        return ans;
	    }
	};
-------------------------------------------------------------
/*
	M3: Stack
	O(n) time and O(n) space
*/
	class Solution {
	public:
	    int longestValidParentheses(string str) {
			int ans = 0;
			std::stack<int> s;
			for(int i=0;i<str.size();i++){
				char c = str[i];
				if(c == '('){
					s.push(i);
				}
				else{
					if(s.size() > 0){
						if(str[s.top()] == '(') s.pop();
						else s.push(i);
					}
					else s.push(i);
				}
			}
			if(s.size() == 0) ans = str.size();
			else{
				int last = str.size() ;
				while(!s.empty()){
					if(last - s.top() + 1 > ans) ans = last - s.top() - 1;
					last = s.top();
					s.pop();
				}
				if(last > ans) ans = last ;
			}		
			return ans;
	    }
	};
-------------------------------------------------------------
/*
	M4: Left and Right Linear Scan
	O(n) time and O(1) space
*/
	class Solution {
	public:
	    int longestValidParentheses(string s) {
	        int open = 0, close = 0;
	        int ans = 0;
	        int n = s.size();
	        for(int i = 0; i < n; i ++){
	            char c = s[i];
	            if(c == '('){
	                open ++;
	            }
	            else{
	                close ++;
	            }
	            if(close > open){
	                close = 0;
	                open = 0;
	            }
	            else if(open == close){
	                ans = max(ans, open + close);
	            }
	        }
	        open = 0, close = 0;
	        for(int i = n - 1; i >= 0; i --){
	            char c = s[i];
	            if(c == '('){
	                open ++;
	            }
	            else{
	                close ++;
	            }
	            if(close < open){
	                close = 0;
	                open = 0;
	            }
	            else if(open == close){
	                ans = max(ans, open + close);
	            }
	        }
	        return ans;
	    }
	};
-------------------------------------------------------------