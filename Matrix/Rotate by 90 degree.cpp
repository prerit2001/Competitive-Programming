#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
public:     
    void rotateby90(vector<vector<int> >& a, int n) 
    { 
        // code here 
        int b[n][n];
        for(int i=0;i<n;i++){
            vector<int> v = a[i];
            int cnt = 0;
            for(int j=0;j<n;j++){
                b[j][i] = v[cnt++]; 
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j] = b[n-i-1][j];
            }
        }
    } 
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}  