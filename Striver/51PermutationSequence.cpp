/*https://leetcode.com/problems/permutation-sequence/*/
--------------------------------------------------------------------------------------
/*
	M1: Brute force
	O(n!) time and O(1) space
*/
	class Solution {
	public:
	    string getPermutation(int n, int k) {
	        string s(n, '0');
	        iota(s.begin(), s.end(), '1');
	        do{
	            k --;
	            if(k == 0) {
	                return s;
	            }
	        }while(next_permutation(s.begin(), s.end()));
	        return "";
	    }
	};
--------------------------------------------------------------------------------------
/*
	M2: Smart Step By Step Considerarion
	O(n * 9) time and O(9) space
*/
	class Solution {
	public:
	    string getPermutation(int n, int k) {
	        string ans(n, '0');
	        set<char> s;
	        vector<int> fact = {1,1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	        for(int i = 0; i < n; i ++){
	            int pre = 0;
	            for(char c = '1'; c <= char(n + '0'); c ++){
	                if(s.count(c)) continue;
	                pre += 1;
	                if(pre * fact[n - i - 1] >= k){
	                    s.insert(c);
	                    ans[i] = c;
	                    k -= (pre - 1) * fact[n - i - 1];
	                    break;
	                }
	            }
	        }
	        return ans;
	    }
	};
--------------------------------------------------------------------------------------