//https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1#

string printSequence(string S)
{
    //code here.
    string a[26];
    string s = "";
    char c = '2';
    for(int i=0;i<26;){
        if(i >= 23) break; 
        s = c;
        if(i == 15 or i == 22){
            for(int j=i;j<i+4 and j<26 ;j++){
                a[j] = s;
                s += c;
            }
            i = i+4;
        }
        else{
            for(int j=i;j<i+3 and j<26;j++){
                a[j] = s;
                s += c;
            }  
            i = i+3;
        }
        c = c + 1;
    }
    string ans = "";
    for(auto it : S){
        if(it == ' ') ans += '0';
        else ans += a[it-'A'];
    }
    return ans;
}