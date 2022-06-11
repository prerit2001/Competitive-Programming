/*https://leetcode.com/problems/kth-largest-element-in-an-array/*/
----------------------------------------------------------------------------
/*
	M1: Brute Force 
	O(nlogn) time and O(1) space
*/
----------------------------------------------------------------------------
/*
	M2: Heaps
	O(klogk) time and O(k) space
*/
----------------------------------------------------------------------------
/*
	M3: Bucket Sort with random shuffle(To takel worst TC)
	Better that O(nlogn) time and O(n) space
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
----------------------------------------------------------------------------