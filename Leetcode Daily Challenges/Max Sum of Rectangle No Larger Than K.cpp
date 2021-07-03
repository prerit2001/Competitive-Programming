class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -(1e5 + 5);
        
        for(int i = 0; i < n; i ++){
            int col[m];
            memset(col, 0, sizeof col);
            for(int r = i; r < n; r ++){
                for(int c = 0; c < m; c ++){
                    col[c] += matrix[r][c];
                }
                
                int sum=0;
                set<int> s;
                s.insert(sum);
                for(int c = 0; c < m; c ++){
                    int num = col[c];
                    sum+=num;
                    auto tmp = s.lower_bound(sum-k);
                    if(tmp != s.end()) ans = max(ans, sum- *tmp);
                    s.insert(sum);
                }
                
            }
        }
        return ans;
    }
};