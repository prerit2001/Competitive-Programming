/*
	O(nlogn) avg and O(n^2) worst
*/
#include<bits/stdc++.h>
using namespace std;

// function to fix the position of pivot element
int partition(int low, int high, vector<int>& v){
	int pivot = high;
	int size = v.size();

	for(int i = low; i < pivot; ){
		if(v[i] > v[pivot]){
			swap(v[i], v[pivot]);
			swap(v[i], v[pivot - 1]);
			pivot -= 1;
		}
		else{
			i += 1;
		}
	}

	return pivot;
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
