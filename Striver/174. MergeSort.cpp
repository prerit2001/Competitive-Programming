/*
	O(nlogn) time best worst avg
*/
#include<bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int>& v){
	int i = low;
	int j = mid + 1;
	
	vector<int> temp(high - low + 1);
	int index = 0;

	while(i <= mid and j <= high){
		if(v[i] < v[j]){
			temp[index] = v[i];
			i += 1;
			index += 1;
		}
		else{
			temp[index] = v[j];
			j += 1;
			index += 1;
		}
	}

	while(i <= mid){
		temp[index] = v[i];
		i += 1;
		index += 1;
	}

	while(j <= high){
		temp[index] = v[j];
		j += 1;
		index += 1;
	}

	for(int i = low; i <= high; i ++){
		v[i] = temp[i - low];
	}
}

void mergeSort(int low, int high, vector<int>& v){
	if(low == high){
		return;
	}
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(low, mid, v);
		mergetSort(mid + 1, high, v);

		merge(low, mid, high, v);
	}
}

int main(){
	
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i ++){
		cin >> v[i];
	}

	mergeSort(0, n - 1, v);

	for(int i = 0; i < n; i ++){
		cout << v[i] << " ";
	}

	return 0;

}
