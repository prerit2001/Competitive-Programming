/*
* Given an array arr[] of N non-negative
* integers representing the height of blocks.
* If width of each block is 1, compute how
* much water can be trapped between the blocks
* during the rainy season. 
*/


#include<bits/stdc++.h>
using namespace std;

int trappingWater(int a[], int n){
        int i,left=0,right=n-1;
        for(i=0;i<n;i++){
            if(a[i]>0){
                left = i;
                break;
            }
        }
        for(i=n-1;i>=0;i--){
            if(a[i]>0){
                right = i;
                break;
            }
        }
        int ans = 0;
        int flag = 1;
        int mid = n+1;
        for(i=left;i<=right;i++){
            int start = i, stop = n+1;
            int sum = 0;
            while(i<=right){
                if(a[i]>=a[start] and i!=start){
                    stop = i;
                    break;
                }
                else{
                    sum += a[start]-a[i];
                    i++;
                }
            }
            if(stop==n+1){
                mid = start;
                break;
            }
            ans+=sum;
            i--;
        }
        for(i=right;i>=mid;i--){
            int start = i, stop = mid-1;
            int sum = 0;
            while(i>=mid){
                if(a[i]>=a[start] and i!=start){
                    stop = i;
                    break;
                }
                else{
                    sum += a[start]-a[i];
                    i--;
                }
            }
            if(stop==mid-1){
                mid = start;
                break;
            }
            ans+=sum;
            i++;
        }
        return ans;   
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        cout << trappingWater(a, n) << endl;
    }
    
    return 0;
} 


/* 
* TC : O(n)
* Auxilary Space : O(1)
*/