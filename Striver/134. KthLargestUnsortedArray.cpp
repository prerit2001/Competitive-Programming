/*https://leetcode.com/problems/kth-largest-element-in-an-array/*/
--------------------------------------------------------------------
/*
	M1: Sort the Array 
	O(nlogn) time and O(1) space
*/
--------------------------------------------------------------------
/*
	M2: Priority Queue / Ordered Map or Set
	O(klogk) time and O(k) space
*/
--------------------------------------------------------------------
/*
	M3: Quick Sort Partition Method
	O(N) best case / O(N^2) worst case running time and O(1) space
*/
	int findKthLargest(int[] nums, int k) {

        k = nums.length - k;
        int lo = 0;
        int hi = nums.length - 1;
        while (lo < hi) {
            final int j = partition(nums, lo, hi);
            if(j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }

    int partition(int[] a, int lo, int hi) {

        int i = lo;
        int j = hi + 1;
        while(true) {
            while(i < hi && less(a[++i], a[lo]));
            while(j > lo && less(a[lo], a[--j]));
            if(i >= j) {
                break;
            }
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }

    void exch(int[] a, int i, int j) {
        final int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    boolean less(int v, int w) {
        return v < w;
    }
----------------------------------------------------------------------------
/*
	M4: So how can we improve the above solution and 
		make it O(N) guaranteed? The answer is quite 
		simple, we can randomize the input, so that 
		even when the worst case input would be provided 
		the algorithm wouldn't be affected. So all what 
		it is needed to be done is to shuffle the input.
	O(N) guaranteed running time + O(1) space
*/
	class Solution {
	public:
	    void shuffle(vector<int>& nums){
	        int n = nums.size();
	        for(int i = 0; i < n; i ++){
	            int randomId = rand() % n;
	            swap(nums[i], nums[randomId]);
	        }
	    }
	    int partition(vector<int>& nums, int low, int high){
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
	    int findKthLargest(vector<int>& nums, int k) {
	        shuffle(nums);
	        int n = nums.size();
	        k = n - k;
	        int low = 0, high = nums.size() - 1;
	        while(low <= high){
	            int correctIndex = partition(nums, low, high);
	            if(correctIndex == k){
	                break;
	            }
	            else if(correctIndex > k){
	                high = correctIndex - 1;
	            }
	            else{
	                low = correctIndex + 1;
	            }
	        }
	        return nums[k];
	    }
	};
-------------------------------------------------------------------