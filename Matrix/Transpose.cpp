
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
public:     
    void transpose(vector<vector<int> >& a, int n)
    { 
        
        vector<int> b(n*n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         b[j*n + i] = a[i][j];
        int cnt = 0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         a[i][j] = b[cnt++];

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
        ob.transpose(matrix,n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}  