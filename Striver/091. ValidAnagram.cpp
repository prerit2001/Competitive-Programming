/*https://leetcode.com/problems/valid-anagram/*/
-------------------------------------------------------
/*
	M1: dictionary comparison
	O(n) time and O(distinct characters) space
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        long long a[26]={};
        if(s.size()!=t.size())return false;
        for(long i=0;i<s.size();i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=0)return false;
        }
        return true;
    }
};
-------------------------------------------------------
/*
	m2: Sorting
	O(nlogn) time and O(1) space
*/
class Solution {
public:
    bool isAnagram(string s, string t) { 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};
-------------------------------------------------------