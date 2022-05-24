/*https://www.codingninjas.com/codestudio/problems/975344*/
/*
    M1: Memoization
    Time Complexity: O(N ^ 3) 
    Note: It is the upper bound. In real Time Complexity will be much lesser.
    
    Space Complexity: O(N * N)

    Where 'N' is the number of elements in the array.
*/ 
int dp[102][102];

int calculateCost(vector<int> &arr, int i, int j){
    if(i >= j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = calculateCost(arr, i, k) + calculateCost(arr, k + 1, j) + (arr[k] * arr[i - 1] * arr[j]);
        ans = min(ans, temp);
    }
    dp[i][j] = ans;
    return ans;
}

int matrixMultiplication(vector<int> &arr, int N){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            dp[i][j] = -1;
        }
    }

    int ans = calculateCost(arr, 1, N - 1);
    return ans;
}
/*
    M2: Tabulation
    Time Complexity: O(N ^ 3) 
    Note: It is the upper bound. In real Time Complexity will be much lesser.
    
    Space Complexity: O(N * N)

    Where 'N' is the number of elements in the array.
*/ 
int matrixMultiplication(vector<int> &arr, int N){
    int dp[N][N];
    /* 
        State: dp[i, j] = Minimum number of scalar
        multiplications needed to compute the
        matrix A[i]A[i+1]...A[j] = A[i..j] where
        dimension of A[i] is arr[i-1] x arr[i] 
    */
    for (int i = 1; i < N; i++){
        dp[i][i] = 0;
    }
       
    for (int l = 2; l < N; l++){
        for (int i = 1; i < N - l + 1; i++){
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++){
                int temp = dp[i][k] + dp[k + 1][j]  + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    return dp[1][N - 1];
}