// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
       // code here 
        int x = 0 , y = 0;
        int cnt = r * c;
        string s = "R";
        set<pair<int,int>> ss;
        vector<int> b;
        while(cnt --){
            if(s == "R"){
                if(ss.count({x,y} )||( y>=c)){
                    s = "D";
                    cnt++;
                    y--;
                    x++;
                }
                else{
                    b.push_back(a[x][y]);
                    ss.insert({x,y});
                    y++;
                    continue;
                }
            }
            else if(s == "D"){
                if(ss.count({x,y} )||( x>=r)){
                    s = "L";
                    cnt++;
                    x--;
                    y--;
                }
                else{
                    b.push_back(a[x][y]);
                    ss.insert({x,y});
                    x++;
                    continue;
                }
            }
            else if(s == "L"){
                if(ss.count({x,y} )||( y<0)){
                    s = "U";
                    cnt++;
                    y++;
                    x--;
                }
                else{
                    b.push_back(a[x][y]);
                    ss.insert({x,y});
                    y--;
                    continue;
                }
            }
            else if(s == "U"){
                if(ss.count({x,y}) ||( x<0)){
                    s = "R";
                    cnt++;
                    x++;
                    y++;
                }
                else{
                    b.push_back(a[x][y]);
                    ss.insert({x,y});
                    x--;
                    continue;
                }
            }
        }
        return b;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for(int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends