// https://practice.geeksforgeeks.org/problems/next-permutation5226/1

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int index = -1;
        for(int i = N - 1; i >= 1; i--){
            if(arr[i - 1] < arr[i]){
                index = i - 1;  
                break;
            }
        }
        if(index == -1){
            reverse(arr.begin(), arr.end());    
            return arr;
        }
        auto it = lower_bound(arr.rbegin(), arr.rend() - index, arr[index]);
        swap(arr[index], *it);
        reverse(arr.begin() + index + 1, arr.end());        
        return arr;
    }
};