/*https://leetcode.com/problems/minimum-cost-to-cut-a-stick/*/
/*
	M1: Memo
    O(n^3) time and O(n^2) space
*/
int dp[105][105];
class Solution {
public:
    int rodCutting(int leftIdx, int rightIdx, int n, vector<int>& cuts){
        if(leftIdx > rightIdx){
            return 0;
        }
        if(dp[leftIdx][rightIdx] != -1){
        	return dp[leftIdx][rightIdx];
        }
    	int ans = 1e8;
    	for(int i = leftIdx; i <= rightIdx; i ++){
    		
    		int leftCutCost = rodCutting(leftIdx, i - 1, n, cuts); 
    		int rightCutCost = rodCutting(i + 1, rightIdx, n, cuts);
    		
    		int Cost_Cutting_At_I = 0;
    		
    		if(leftIdx == 0) Cost_Cutting_At_I += cuts[i];
    		else Cost_Cutting_At_I += cuts[i] - cuts[leftIdx - 1];
    		
    		if(rightIdx == cuts.size() - 1) Cost_Cutting_At_I += n - cuts[i];
    		else Cost_Cutting_At_I += cuts[rightIdx + 1] - cuts[i];
    		
    		ans = min(ans, Cost_Cutting_At_I + leftCutCost + rightCutCost);
    	}
    	return dp[leftIdx][rightIdx] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
    	memset(dp, -1, sizeof dp);
        sort(cuts.begin(), cuts.end());
        return rodCutting(0, cuts.size() - 1, n, cuts);
    }
};
/*
    M2: Tablulation
    O(n^3) time and O(n^2) space
*/
public int minCost(int n, int[] cuts) {
    var c = new ArrayList<Integer>();
    for (int cut : cuts)
        c.add(cut);
    c.addAll(Arrays.asList(0, n));
    Collections.sort(c);
    int[][] dp = new int[c.size()][c.size()];
    for (int i = c.size() - 1; i >= 0; --i)
        for (int j = i + 1; j < c.size(); ++j) {
            for (int k = i + 1; k < j; ++k)
                dp[i][j] = Math.min(dp[i][j] == 0 ? Integer.MAX_VALUE : dp[i][j],
                    c.get(j) - c.get(i) + dp[i][k] + dp[k][j]);
        }
    return dp[0][c.size() - 1];    
}