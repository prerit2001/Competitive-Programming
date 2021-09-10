/*https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/*/

/*
	M1 : Brute force
	O(n * m) time and O(1) space  
*/

	void solve(vector<int> a, int n, vector<int> b, int m){
		int ptr1 = 0, ptr2 = 0;
		if(m == 0) return;
		while(ptr1 < n and ptr2 < m){
			if(a[ptr1] > b[ptr2]){
				swap(a[ptr1], b[ptr2]);
				int j = ptr2;
				while(j + 1 < m){
					if(a[j + 1] < a[j]) swap(a[j], a[j+1]);
					else break;
					j ++;
				}
			}
		}
	}

/*
	M2 : Gap Sort
	O(nlogn) time and O(1) space
*/

	int next_gap(int gap){
		return (gap + 1) / 2;
	}

	void solve(vector<int> a, int n, vector<int> b, int m){
		int gap = n + m;
		for(gap = next_gap(gap); gap > 0; gap = next_gap(gap)){
			int i = 0;
			for(i = 0; i + gap < n; i ++){
				if(a[i] > a[i+gap]) swap(a[i], a[i+gap]);
			}
			int j = max(gap - n, 0);
			for(; i < n and j < m; i ++, j ++){
				if(a[i] > b[j]){
					swap(a[i],b[j]);
				}
			}
			for(j = 0; j + gap < m; j ++){
				if(b[j] > b[j + gap]) swap(b[j], b[j + gap]);
			}
		}
	}
