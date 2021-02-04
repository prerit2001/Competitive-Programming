
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	long long maxProduct(int *arr, int n) {
	   long long maxi = arr[0] , mini = arr[0];
	   long long ans = arr[0];
	   for(int i=1;i<n;i++){
	       if(arr[i]<0)
	            swap(maxi,mini);
            maxi = max((long long)arr[i],maxi*arr[i]);
            mini = min((long long)arr[i],mini*arr[i]);
            ans = max((long long)ans,maxi);
	   }
	   return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  