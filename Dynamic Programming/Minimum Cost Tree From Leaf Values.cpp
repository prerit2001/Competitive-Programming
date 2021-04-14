/*
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& a) {
        int n = a.size();
        if(n == 1){
        	return 0;
        } 
        if(n == 2){
        	return a[0]*a[1];
        }   
        int sum = 0;
        while(n > 1){
            int product = INT_MAX;
            for(int i=0;i<n-1;i++){
                product = min(a[i]*a[i+1],product);
            }
            for(int i=0;i<n-1;i++){
                if(a[i]*a[i+1] == product){
                    auto it = a.begin();
                    int A,B;
                    A = a[i];
                    B = a[i+1];
                    a.erase(it+i);
                    a.erase(it+i);
                    a.insert(it + i , max(A,B));
                    n-=1;
                    break;
                }
            }
            sum += product;
        }
        return sum;
    }
};