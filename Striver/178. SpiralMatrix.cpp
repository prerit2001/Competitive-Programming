/*https://leetcode.com/problems/spiral-matrix/*/
-------------------------------------------------------------------------
/*
	O(n*m) time and O(1) space
*/
#define ll long long

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        
        int n = v.size();
        int m = v[0].size();    
        
        vector<int> ans;
        
        pair<ll, ll> LT = {0, 0};
        pair<ll, ll> RT = {0, m - 1};
        pair<ll, ll> LB = {n - 1, 0};
        pair<ll, ll> RB = {n - 1, m - 1};


        while(LT.first <= LB.first and RT.second >= LT.second){
            
            int i = LT.second;
            while(i <= RT.second)
                ans.push_back(v[LT.first][i]);
                i ++;
            }

            i = RT.first + 1;
            while(i <= RB.first){
                ans.push_back(v[i][RT.second]);
                i ++;
            }
            
            if(LT.first < LB.first){
                i = RB.second - 1;
                while(i >= LB.second){
                    ans.push_back(v[RB.first][i]);
                    i --;
                }
            }
            
            if(LT.second < RT.second){
                i = LB.first - 1
                while(i >= LT.first + 1){
                    ans.push_back(v[i][LB.second]);
                    i --;
                }
            }
           

            LT.first += 1;
            LT.second += 1;

            LB.first -= 1;
            LB.second += 1;

            RT.first += 1;
            RT.second -= 1;

            RB.first -= 1;
            RB.second -= 1;

        }
        
        return ans;
        
    }
};
-------------------------------------------------------------------------