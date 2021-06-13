// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1#

int romanToDecimal(string &str) {
    // code here
    int ans = 0;
    map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int last = 0;
    for(int i = str.size() - 1; i >= 0; i --){
        if(mp[str[i]] >= last){
            ans += mp[str[i]];
            last = mp[str[i]];
        }   
        else{
            ans -= mp[str[i]];
        }
    }
    return ans;
}