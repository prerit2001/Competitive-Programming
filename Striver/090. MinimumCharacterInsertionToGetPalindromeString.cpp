/*https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/*/
----------------------------------------------------------------------------------------------------
/*
    M1: LPS Array
    O(n) time and O(n) space


    eg -> s = AACECAAAA

    if we somehow genrate the lps of (s + "$" + reverse(s))
    answer will be n - lps value of last index  
*/

vector<int> LPS(string s){
    int n = s.size();
    vector<int> lps(n, 0);
    for(int i = 1, len = 0; i < n; ){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            i ++, len ++;
        }
        else if(len > 0){
            len = lps[len - 1];
        }
        else{
            lps[i] = 0;
            i ++;
        }
    }
    return lps;
}

int Solution::solve(string s) {
    int n = s.size();
    string k = s;
    reverse(s.begin(), s.end());
    vector<int> lps = LPS(k + '$' + s);
    int ans = n - lps.back();
    return ans;
}
---------------------------------------------------------------------