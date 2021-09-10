/*https://leetcode.com/problems/set-matrix-zeroes/*/
---------------------------------------------------------------------------
/* 
	M1 : Brute force Aditional Memory
	O(n^2) time and O(n) space 
*/
---------------------------------------------------------------------------
/*
	M2 : if(a[i][j] == 0) then a[i][0] = 0, a[0][j] = 0 then proceed
	O(n^2) time and O(1) space
*/
	void setZeroes(vector<vector<int>>& matrix) {
        int flagi = 1, flagj = 1;
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j ++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0) flagi = 0;
                    if(j == 0) flagj = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i ++){
            for(int j = 1; j < matrix[0].size(); j ++){
                if(matrix[i][0] == 0 or matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(flagj == 0){
            for(int i = 0; i < matrix.size(); i ++){
                matrix[i][0] = 0;
            }
        }
        if(flagi == 0){
            for(int j = 0; j < matrix[0].size(); j ++){
                matrix[0][j] = 0;
            }
        }
    }
-----------------------------------------------------------------------