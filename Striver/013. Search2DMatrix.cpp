/*https://leetcode.com/problems/search-a-2d-matrix/*/
-------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
-------------------------------------------------------------------------
/*
	M2 : Linear Searching
	O(n + m) time and O(1) space
*/
	class Solution {
	public:
	    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	        int i = 0;
	        int j = 0;
	        int n = matrix.size();
	        int m = matrix[0].size();
	        int last = 0;
	        while(i < n){
	            if(matrix[i][0] > target) break;
	            last = i;
	            i ++;
	        }
	        while(j < m){
	            if(matrix[last][j] == target) return 1;
	            j ++;
	        }
	        return 0;
	    }
	};
-------------------------------------------------------------------------
/*
	M2 : Binary search Twice
	O(logn + logm) time and O(1) space 
*/
	class Solution {
	public:
	    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	        int n = matrix.size() - 1;
	        int m = matrix[0].size() - 1;
	        int i = 0;
	        int j = 0;
	        int last = 0;
	        while(i < n){
	            int mid = (i + n + 1) >> 1;
	            if(matrix[mid][0] <= target){
	                i = mid;
	            }
	            else{
	                n = mid - 1;
	            }
	        }
	        while(j < m){
	            int mid = (j + m + 1) >> 1;
	            if(matrix[i][mid] <= target){
	                j = mid;
	            }
	            else{
	                m = mid - 1;
	            }
	        }
	        return matrix[i][j] == target;
	    }
	};
-------------------------------------------------------------------------