/*https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1*/
--------------------------------------------------------------------------------------
/*
	M1: Backtracting
	O(3^(n^2)) time complexity and O(3^(n^2)) space complexity(Rec call stack)
*/	
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};

	int cnt = 0;

	class Solution{
	    public:
	    vector<string> ans;
	    void go(int i, int j, int di, int dj, string s, vector<vector<int>> m, vector<vector<int>> vis){
	        if(i == di and j == dj){
	            ans.push_back(s);
	            return;
	        }
	        vis[i][j] = 1;
	        for(int k = 0; k < 4; k ++){
	            int x = i + dx[k];
	            int y = j + dy[k];
	            char c;
	            if(k == 0) c = 'D';
	            if(k == 1) c = 'U';
	            if(k == 2) c = 'R';
	            if(k == 3) c = 'L';
	            if(x < 0 or y < 0){
	                continue;
	            }
	            if(x > di or y > dj){
	                continue;
	            }
	            if(m[x][y] == 0){
	                continue;
	            }
	            if(vis[x][y] == 0){
	                go(x,y,di,dj,s+c,m,vis);
	            }
	        }
	        vis[i][j] = 0;
	    }
	    vector<string> findPath(vector<vector<int>> &m, int n) {
	        if(m[0][0] == 0) return {};
	        vector<vector<int>> vis(m.size(),vector<int>(m.size(),0));
	        go(0,0,m.size() - 1,m.size() - 1,"",m,vis);
	        sort(ans.begin(),ans.end());
	        return ans;
	    }
	};
--------------------------------------------------------------------------------------
