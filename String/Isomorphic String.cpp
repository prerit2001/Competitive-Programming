// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#

#include<bits/stdc++.h>

class Solution
{
    public:
    bool areIsomorphic(string str1, string str2){
        if(str1.size() != str2.size()) return false;
        map<char,int> mp1,mp2;
        for(int i=0;i<str1.size();i++){
            if(mp1.count(str1[i]) and mp1[str1[i]] != str2[i] ) return false;
            if(mp2.count(str2[i]) and mp2[str2[i]] != str1[i] ) return false;
            mp1[str1[i]] = str2[i];
            mp2[str2[i]] = str1[i];
        }
        return true;
    }
};