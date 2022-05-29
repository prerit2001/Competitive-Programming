/*
	O(nlogn) avg and O(n^2) worst
*/
#include<bits/stdc++.h>
using namespace std;

// function to fix the position of pivot element
int partition(int low, int high, vector<int>& nums){
	int idToCorrect = high;
    for(int i = low; i < idToCorrect; ){
        if(nums[i] >= nums[idToCorrect]){
            if(idToCorrect - i >= 2){ 
                swap(nums[idToCorrect], nums[idToCorrect - 1]);
                swap(nums[idToCorrect], nums[i]);
                idToCorrect --;
            }
            else{
                swap(nums[idToCorrect], nums[i]);
                idToCorrect --;
                i ++;
            }
        }
        else{
            i ++;
        }
    }
    return idToCorrect;
}

void quickSort(int low, int high, vector<int>& v){
	if(low == high){
		return;
	}
	if(low < high){
		int pivot = partition(low, high, v);

		quickSort(low, pivot - 1, v);
		quickSort(pivot + 1, high, v);
	}
} 

int main(){
	
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i ++){
		cin >> v[i];
	}

	quickSort(0, n - 1, v);

	for(int i = 0; i < n; i ++){
		cout << v[i] << " ";
	}

	return 0;
}
