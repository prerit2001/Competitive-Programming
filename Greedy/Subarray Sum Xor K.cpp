#include <bits/stdc++.h>
using namespace std;
 
long long subarrayXor(int arr[], int n, int m){
    long long ans = 0; 
    int* xorArr = new int[n];
    unordered_map<int, int> mp;
    xorArr[0] = arr[0];

    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];
 
    for (int i = 0; i < n; i++) {
        int tmp = m ^ xorArr[i];
        ans = ans + ((long long)mp[tmp]);
        if (xorArr[i] == m)
            ans++;
        mp[xorArr[i]]++;
    }
    return ans;
}
 
int main()
{
    int arr[] = { 4, 2, 2, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 6;
 
    cout << "Number of subarrays having given XOR is "
         << subarrayXor(arr, n, m);
    return 0;
}