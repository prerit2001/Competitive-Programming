class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        
        // check all negative
        bool neg = 1;
        int maxi = matrix[0][0];
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(matrix[i][j] >= 0) neg = 0;
                maxi = max(matrix[i][j],maxi);
            }
        }
        if(neg) return maxi;
        
        for(int i = 0; i < n; i ++){
            int col[m];
            memset(col, 0, sizeof col);
            for(int r = i; r < n; r ++){
                for(int c = 0; c < m; c ++){
                    col[c] += matrix[r][c];
                }
                // kadane's
                int max_so_far = 0;
                int sum_so_far = 0;
                for(int c = 0; c < m; c ++){
                    sum_so_far += col[c];
                    if(sum_so_far < 0){
                        sum_so_far = 0;
                    }
                    else{
                        max_so_far = max(max_so_far, sum_so_far);
                    }
                }
                ans = max(ans, max_so_far);
            }
        }
        return ans;
    }
};
