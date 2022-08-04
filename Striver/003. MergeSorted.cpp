/*https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/*/
-------------------------------------------------------------------------------------------
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
-------------------------------------------------------------------------------------------
/*
	M2 : Gap Sort #striver last 5 min vid
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

	## Aither

	class Solution{
	    public:
	        //Function to merge the arrays.
	        void merge(long long arr1[], long long arr2[], int n, int m) 
	        { 
	            // code here
	            int gap = (n + m + 1) / 2;
	            while(1){
	                int i = 0, j = gap;
	                for(; j < n + m; i ++, j ++){
	                    int f = i;
	                    if(f >= n){ 
	                        f = f - n;
	                        int s = j;
	                        if(s >= n){
	                            s = s - n;
	                            if(arr2[f] > arr2[s]) 
	                            	swap(arr2[f], arr2[s]);
	                        }
	                        else{
	                            // not possible
	                        }
	                    }
	                    else{
	                        int s = j;
	                        if(s >= n){ 
	                            s = s - n;
	                            if(arr1[f] > arr2[s]) swap(arr1[f], arr2[s]);
	                        }
	                        else{
	                            if(arr1[f] > arr1[s]) swap(arr1[f], arr1[s]);
	                        }
	                    }
	                }
	                if(gap <= 1) break; 
	                gap = (gap + 1) / 2;
	            }
	        } 
	};
----------------------------------------------------------------------------------
/*
	M3: Two Pointers(Reverse Merging) If Problem is Leetcode types
	O(n + m) time and O(1) space  
*/
	class Solution {
	public:
	    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	        int i = m - 1, j = n - 1, k = n + m - 1;
	        while(j >= 0){
	            if(i < 0 or nums1[i] < nums2[j]){
	                nums1[k] = nums2[j];
	                k --, j --;
	            }	
	            else{
	                nums1[k] = nums1[i];
	                k --; i --;
	            }
	        }
	    }
	};
----------------------------------------------------------------------------------
