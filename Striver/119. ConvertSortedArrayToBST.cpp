/*https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/*/
/*
	M1: Range Param Recur
	O(n) time and O(logn) Call Stack
*/
    class Solution {
     public:
   		TreeNode* sortedArrayToBST(vector<int>& nums) {
   			return  binary_Search(nums, 0, nums.size()-1);   
  		}
		TreeNode*  binary_Search(vector<int> &nums, int low, int high){
		  	if(low>high)
		      	return NULL;
		  
	        int mid =low + (high -low)/2;
	        TreeNode* root = new TreeNode();
	        root->val = nums[mid];
	        root->left = binary_Search(nums, low, mid -1);
	        root->right = binary_Search(nums, mid+1, high);
	        return root;
		}
	}