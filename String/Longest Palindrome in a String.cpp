// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1


class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int left = 0,right=0;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int res = 1;
            for(int cnt=1;cnt<=n;cnt++){
                if(i-cnt >= 0 and i-cnt < n and s[i-cnt] == s[i+cnt]) res += 2; 
                else break;
            }
            if(ans < res) ans = res, left = i-(res-1)/2, right = i + (res-1)/2;
        }
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                int res = 2;
                for(int cnt=1;cnt<=n;cnt++){
                    if(i-cnt-1 >= 0 and i-cnt < n and s[i-1-cnt] == s[i+cnt]) res += 2; 
                    else break;
                }
                if(ans < res) ans = res, left = i-1-(res-2)/2, right = i + (res-2)/2;
            }
        }
        return s.substr(left,right - left + 1);
    }
};


// other dp approach : https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/