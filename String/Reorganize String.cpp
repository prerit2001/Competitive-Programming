// https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string str) {
        int a[26];
        memset(a, 0, sizeof a);
        int n = str.size();
        for(auto it : str){
            a[it - 'a'] ++;
        }
        for(int i=0;i<26;i++){
            if(n&1 and a[i] > (n/2+1)) return "";
            else if(~n&1 and a[i] > n/2) return "";
        }
        string s(n,'0');
        int last = 0;
        for(int i=0; i<n ; i+=2){
            int pos = 0, maxi = 0;
            for(int j=0;j<26;j++){
                if(a[j] > maxi){
                    maxi = a[j];
                    pos = j;
                }
            }
            while(a[pos] > 0 and i < n){
                a[pos] --;
                s[i] = char(pos + 'a');
                i += 2;
            }
            i -= 2;
            last = pos;
        }
        int idx = 1;
        while(a[last] > 0 and idx < n){
            a[last] --;
            s[idx] = char(last + 'a');
            idx += 2;
        }
        for(int i=idx; i<n ; i+=2){
            int pos = 0, maxi = 0;
            for(int j=0;j<26;j++){
                if(a[j] > maxi){
                    maxi = a[j];
                    pos = j;
                }
            }
            while(a[pos] > 0 and i < n){
                a[pos] --;
                s[i] = char(pos + 'a');
                i += 2;
            }
            i -= 2;
        }
        return s;
    }
};