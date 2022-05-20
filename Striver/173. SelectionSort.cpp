/*
	O(n^2) time 
*/
/*
	Lets consider the following array as an example: arr[] = {64, 25, 12, 22, 11}
	First pass:

		For the first position in the sorted array, the whole array is traversed from index 0 to 4 sequentially. The first position where 64 is stored presently, after traversing whole array it is clear that 11 is the lowest value.
   			64   	   25   	   12   	   22   	   11   
		Thus, replace 64 with 11. After one iteration 11, which happens to be the least value in the array, tends to appear in the first position of the sorted list.
   			11   	   25   	   12   	   22   	   64   

	Second Pass:

		For the second position, where 25 is present, again traverse the rest of the array in a sequential manner.
		   11   	   25   	   12   	   22   	   64   
		After traversing, we found that 12 is the second lowest value in the array and it should appear at the second place in the array, thus swap these values.
		   11   	   12   	   25   	   22   	   64   

	.
	.
	.

*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int n, vector<int>& v){

	for(int i = 0; i < n; i ++){
		int minIdx = i;
		int minVal = v[i];
		for(int j = i; j < n; j ++){
			if(v[j] < v[i]){
				minVal = v[j];
				minIdx = j;
			}
		}
		swap(v[i], v[minIdx]);
	}

}

int main(){

	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i ++){
		cin >> v[i];
	}

	selectionSort(n, v);

	for(int i = 0; i < n; i ++){
		cout << v[i] << " ";
	}

	return 0;
}