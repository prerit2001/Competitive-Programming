/*
https://leetcode.com/problems/count-sorted-vowel-strings/
*/


class Solution {
public:
    int countVowelStrings(int n) {
       int dp[6];
       dp[1] = 1,dp[2] = 1,dp[3] = 1,dp[4] = 1,dp[5] = 1;
       for(int i=1;i<n;i++){
     	  int temp[6] = {};
     	  temp[5] = dp[5];
     	  temp[4] = dp[4]+temp[5];
     	  temp[3] = dp[3]+temp[4];
     	  temp[2] = dp[2]+temp[3];
     	  temp[1] = dp[1]+temp[2];
     	  dp[1]=temp[1];
     	  dp[2]=temp[2];
     	  dp[3]=temp[3];
     	  dp[4]=temp[4];
     	  dp[5]=temp[5];
       }
       return dp[1]+dp[2]+dp[3]+dp[4]+dp[5];
    }
};