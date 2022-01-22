/*https://leetcode.com/problems/reverse-words-in-a-string/*/
-----------------------------------------------------------------------------------------------
/*
	M1: Extract All Words With Extra Space
	O(n) time and O(n) space
	Approach -> 
		step 1-> trim string such that if s = "  hello   world  " => "hello world";
		step 2-> reverse the whole string
		step 3-> reverse all words of the string
*/
	class Solution {
	public:
	    string reverseWords(string s) {
	        int n = s.size();
	        int id = 0;
	        for(int i = 0; i < n; i ++){
	            if(s[i] != ' '){
	                while(i < n and s[i] != ' '){
	                    s[id] = s[i];
	                    i ++, id ++;
	                }
	                s[id] = ' ';
	                id ++;
	            }
	        }
	        s.erase(s.begin() + id - 1, s.end()); 
	        n = s.size();
	        reverse(s.begin(), s.end());
	        for(int i = 0; i < n; i ++){
	            if(s[i] != ' '){
	                string x = "";
	                int startIndex = i;
	                while(i < n and s[i] != ' '){
	                    x += s[i];
	                    i ++;
	                }
	                int endIndex = i - 1;
	                reverse(x.begin(), x.end());
	                for(int j = startIndex; j <= endIndex; j ++){
	                    s[j] = x[j - startIndex];
	                }
	            }
	        }
	        return s;
	    }
	};
-----------------------------------------------------------------------------------------------
/*
	M2: Extract Start Index and End Index of Each Words Without Extra Space and reverse it naively
	O(n) time and O(1) space
	Approach -> 
		step 1-> trim string such that if s = "  hello   world  " => "hello world";
		step 2-> reverse the whole string
		step 3-> reverse all words of the string
*/
	class Solution {
	public:
	    string reverseWords(string s) {
	        int n = s.size();
	        int id = 0;
	        for(int i = 0; i < n; i ++){
	            if(s[i] != ' '){
	                while(i < n and s[i] != ' '){
	                    s[id] = s[i];
	                    i ++, id ++;
	                }
	                s[id] = ' ';
	                id ++;
	            }
	        }
	        s.erase(s.begin() + id - 1, s.end());
	        n = s.size();
	        reverse(s.begin(), s.end());
	        for(int i = 0; i < n; i ++){
	            if(s[i] != ' '){
	                int startIndex = i;
	                while(i < n and s[i] != ' '){
	                    i ++;
	                }
	                int endIndex = i - 1;
	                for(int j = startIndex; j <= (startIndex + endIndex)>>1; j ++){
	                    swap(s[j],s[endIndex - (j - startIndex)]);
	                }
	            }
	        }
	        return s;
	    }
	};
-----------------------------------------------------------------------------------------------