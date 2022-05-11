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
	    int fact(int n){
	        if(n <= 0) return 1; 
	        return n * fact(n - 1);
	    }
	    string getPermutation(int n, int k) {
	        vector<bool> vis(n + 1, false);
	        string ans = "";
	        for(int i = 0; i < n; i ++){
	            for(int j = 0; j < n; j ++){
	                if(vis[j + 1]) continue;
	                int right_elem = n - i - 1;
	                int cur = j + 1;
	                int perm_right = fact(right_elem);
	                if(perm_right < k){
	                    k -= perm_right;
	                    continue;
	                }
	                else{
	                    ans += char(cur + '0');
	                    vis[cur] = true;
	                    break;
	                }
	            }
	        }
	        return ans;
	    }
	};
--------------------------------------------------------------------------------------