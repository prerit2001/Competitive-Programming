/*https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/*/
------------------------------------------------------------------
/*
	M1 : brute force sorting 
	O(nlogn) time and O(1) space
*/
------------------------------------------------------------------
/*
	M2 : Counting Sort
	O(n) time  and O(1) space
*/
------------------------------------------------------------------
/*
	M3 : 2 pass solution
	O(2*n) time and O(1) space
*/	
		class Solution {
		public:
		    void sortColors(vector<int>& nums) {
		        int left = 0, right = nums.size() - 1;
		        for(int i = 0; i < nums.size(); i ++){
		            if(nums[i] == 0){
		                swap(nums[i], nums[left]);
		                left ++;
		            }
		        }
		        for(int i = nums.size() - 1; i >= 0; i --){
		            if(nums[i] == 2){
		                swap(nums[i], nums[right]);
		                right --;
		            }
		        }
		    }
		};

------------------------------------------------------------------
/*
	M4 : Variation of "dutch national flag algorithm"
	O(n) time and O(1) space
*/
		class Solution {
		public:
		    void sortColors(vector<int>& nums) {
		        int left = 0, right = nums.size() - 1;
		        int mid = 0;
		        while(mid <= right){
		            if(nums[mid] == 0){
		                swap(nums[mid], nums[left]);
		                left ++;
		                mid ++;
		            }
		            else if(nums[mid] == 1){
		                mid ++;
		            }
		            else if(nums[mid] == 2){
		                swap(nums[mid], nums[right]);
		                right --;
		            }
		        }
		    }
		};
------------------------------------------------------------------