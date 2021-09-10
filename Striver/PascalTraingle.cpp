/*https://leetcode.com/problems/pascals-triangle/*/
--------------------------------------------------------------------------
/*
	M1 : follow the pattern
*/
	class Solution {
	public:
	    vector<vector<int> > generate(int numRows) {
	        vector<vector<int>> r(numRows);

	        for (int i = 0; i < numRows; i++) {
	            r[i].resize(i + 1);
	            r[i][0] = r[i][i] = 1;
	  
	            for (int j = 1; j < i; j++)
	                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
	        }
	        
	        return r;
	    }
	};
----------------------------------------------------------------------------
/*
	M2 : Combination -- nCr -> rowCi 
*/
	class Solution {
	public:
	    long long int nCr(long long n, long long k)
	    {
	        if (k<0) return 0;
	        if (k*2>n) k = n-k;
	        if (k==0) return 1;
	        int res = n;
	        for (int i=2; i<=k; ++i) {
	            res *= (n-i+1);
	            res /= i;
	        }
	        return res;
	    }
	    vector<int> go(int row){
	        vector<int> ans;
	        for(int col = 0; col < (row+1)/2; col ++){
	            ans.push_back(nCr((row),(col)));
	        }
	        for(int col = (row+1)/2; col < row; col ++){
	            ans.push_back(nCr((row),(row - col)));
	        }
	        ans.push_back(1);
	        return ans;
	    }
	    vector<vector<int>> generate(int n) {
	        vector<vector<int>> ans;
	        for(int i = 0; i < n; i ++) ans.push_back(go(i));
	        return ans;
	    }
	};
--------------------------------------------------------------------------