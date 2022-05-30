/*https://leetcode.com/problems/maximal-rectangle/*/
---------------------------------------------------------------------
/*
	M1: Brute Force
	O(n^4) time and O(n^2) space 

	Using Prefix Sum on Matrix 
*/
----------------------------------------------------------------------
/*
	M2: Stack
	O(n^2) time and O(n^2) space
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        int n = M.size(), m = M[0].size();
        vector<int> heights(m, 0);
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            area = max(area, mah(heights, m));
        }
        return area;
    }
    int mah(vector<int> &arr, int n) {
        vector<int> right(n, n), left(n, -1);
        stack<pair<int, int>> stack;
        for (int i = n-1; i >= 0; --i) {
            if (!stack.size()) {}
            else if (stack.top().first < arr[i]) right[i] = stack.top().second;
            else if (stack.top().first >= arr[i]) {
                while (stack.size() && stack.top().first >= arr[i]) stack.pop();
                if (stack.size()) right[i] = stack.top().second;
            }
            stack.push({arr[i], i});
        }
        while (stack.size()) stack.pop();
        for (int i = 0; i < n; ++i) {
            if (!stack.size()) {}
            else if (stack.top().first < arr[i]) left[i] = stack.top().second;
            else if (stack.top().first >= arr[i]) {
                while (stack.size() && stack.top().first >= arr[i]) stack.pop();
                if (stack.size()) left[i] = stack.top().second;
            }
            stack.push({arr[i], i});
        }
        int area = 0;
        for (int i = 0; i < n; i++){
            area = max(area, (right[i] - left[i] - 1) * arr[i]);
        }
        return area;
    }
};
-----------------------------------------------------------------------------------