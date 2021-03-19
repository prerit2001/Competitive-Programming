#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &a, int r, int c){
        // code here
        int mini = INT_MAX, maxi = 0 ;
        for(auto it : a){
            mini = min(mini,*min_element(it.begin(),it.end()));
            maxi = max(maxi,*max_element(it.begin(),it.end()));
        }
        while(mini<maxi){
            int mid = maxi + mini;
            mid = mid / 2 ;
            int cnt = 0;
            for(int i=0;i<r;i++){
                cnt = cnt + upper_bound(a[i].begin(),a[i].end(), mid) - a[i].begin();
            }
            if(cnt < (r*c+1)/2)mini = mid + 1;
            else maxi = mid;
        }
        return mini;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
} 