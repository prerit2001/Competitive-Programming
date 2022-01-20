/*https://leetcode.com/problems/powx-n/*/
-------------------------------------------------------------------
/*
	M1 : Brute Force (a * a * a * .... (b times))
	O(b) time and O(1) space
*/
------------------------------------------------------------------
/*
	M2 : {(b & 1) ? {b -= 1, res *= a} : {b /= 2, a *= a}};
	O(log2(b)) time and O(1) space
*/
	class Solution {
	public:
	    long double power(double a,long long b){
	    	long double res = 1;
	        while(b > 0){
	            if(b % 2 == 1){
	                res *= (a);
	                b -= 1;
	            }
	            else{
	                a *= a;
	                b /= 2;   
	            }
	        }
	        return res;
	    }
	    double myPow(double x, int n) {
	        if(x == 1) return 1;
	        double ans = power(x,abs(long(n)));
	        if(n < 0) return 1/ans;
	        else return ans;
	    }
	};
------------------------------------------------------------------