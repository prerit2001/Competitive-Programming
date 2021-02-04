/*
https://practice.geeksforgeeks.org/problems/common-elements1132/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            long long i1 = 0, i2 = 0, i3 = 0;
            vector<int> v;
            while(i1<n1 or i2<n2 or i3<n3){
                int f=-INT_MAX,s=-INT_MAX,t=-INT_MAX+1,mini=INT_MAX;
                if(i1<n1){
                    f = A[i1];
                    if(mini>f)mini = f;
                }
                if(i2<n2){
                    s = B[i2];
                     if(mini>s)mini = s;
                }
                if(i3<n3){
                    t = C[i3];
                     if(mini>t)mini = t;
                }
                if(f==s and s==t){
                    if(v.size()==0 or v.back()!=f)v.push_back(f);
                }
                if(mini==f)
                    ++i1;
                if(mini==s)
                    ++i2;
                if(mini==t)
                    ++i3;
            }
            return v;
        }

};

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  