/*https://leetcode.com/problems/n-queens/*/
--------------------------------------------------------------------------------------
/*
	M1: Backtraking Brute Force
	O(n^(2n)) time and O(n^2) space
*/
	class Solution {
	public:
		std::vector<std::vector<std::string> > solveNQueens(int n) {
			std::vector<std::vector<std::string> > res;
			std::vector<std::string> nQueens(n, std::string(n, '.'));
			solveNQueens(res, nQueens, 0, n);
			return res;
		}
	private:
		void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
			if (row == n) {
				res.push_back(nQueens);
				return;
			}
			for (int col = 0; col != n; ++col)
				if (isValid(nQueens, row, col, n)) {
					nQueens[row][col] = 'Q';
					solveNQueens(res, nQueens, row + 1, n);
					nQueens[row][col] = '.';
				}
		}
		bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
			//check if the column had a queen before.
			for (int i = 0; i != row; ++i)
				if (nQueens[i][col] == 'Q')
					return false;
			//check if the 45° diagonal had a queen before.
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
				if (nQueens[i][j] == 'Q')
					return false;
			//check if the 135° diagonal had a queen before.
			for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
				if (nQueens[i][j] == 'Q')
					return false;
			return true;
		}
	};
/*
	M2: Smart Backtraing with hashing
	O(n^n) time and O(1) space
*/
	class Solution {
	public:
		void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
			if (col == n) {
				ans.push_back(board);
				return;
			}


			for (int row = 0; row < n; row++) {
				if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0
				        && upperDiagonal[n - 1 + col - row] == 0) {

								board[row][col] = 'Q';
					leftRow[row] = 1;
					lowerDiagonal[row + col] = 1;
					upperDiagonal[n - 1 + col - row] = 1;
					solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
					board[row][col] = '.';
					leftRow[row] = 0;
					lowerDiagonal[row + col] = 0;
					upperDiagonal[n - 1 + col - row] = 0;
				}
			}
		}
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<vector<string>> ans;
			vector<string> board(n);
			string s(n, '.');
			for (int i = 0; i < n; i++) {
				board[i] = s;
			}
			vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
			solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
			return ans;
		}
	};
--------------------------------------------------------------------------------------