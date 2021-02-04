/*
https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int ans = 0, same = 0;
        for(auto it : mp){
            if(!mp.count(k-it.first))continue;
            if(it.first*2==k){
                same = it.second*(it.second-1)/2;
            }
            else{
                ans += it.second*mp[k-it.first];
            }
        }
        return ans/2+same;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  