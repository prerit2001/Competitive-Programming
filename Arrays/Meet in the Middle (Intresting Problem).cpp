/*
* https://leetcode.com/contest/weekly-contest-227/problems/closest-subsequence-sum/ 
* You are given an integer array nums and an integer goal.
* You want to choose a subsequence of nums such that the sum 
* of its elements is the closest possible to goal. That is, 
* if the sum of the subsequence's elements is sum, then you 
* want to minimize the absolute difference abs(sum - goal).
* Return the minimum possible value of abs(sum - goal).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> first,second;
    void gen_subsets(vector<int> a) {
        int n = a.size(), i, j;
        vector<int> ret;
        for(i = 0; i < (1<<n); i++) {
            int sum = 0;
            for(j=0; j<n; j++)
                if(i & (1 << j))
                    sum += a[j];
            first.emplace_back(sum);
        }
    }

	void genrate_all_subsequence(vector<int> nums,int curr,int init){
		if(curr==nums.size()){
			first.push_back(init);
			return;
		}
		init+=(nums[curr]);
		genrate_all_subsequence(nums,curr+1,init);
		init-=(nums[curr]);
		genrate_all_subsequence(nums,curr+1,init);
	}
    
    int minAbsDifference(vector<int>& nums, int goal) {

        vector<int> temp;
        int v = 0;
        for(int i=0;i<nums.size()/2;i++)
        	temp.push_back(nums[i]);
        
        /* Use Any of the Two genrating all subsequence algorithn*/
        
           // genrate_all_subsequence(temp,0,v);
              gen_subsets(temp);
        
        /* */
        
        second = first;
        first.clear();
        temp.clear();
        for(int i=nums.size()/2;i<nums.size();i++)
        	temp.push_back(nums[i]);
        
        
        /* Use Any of the Two genrating all subsequence algorithn */
        
            // genrate_all_subsequence(temp,0,v);
               gen_subsets(temp);
        
        /* */
    
        
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        vector<int> temp1,temp2;
        for(int i=0;i<first.size();i++){
        	if(i==0 or first[i]!=first[i-1])temp1.push_back(first[i]);
        }
        for(int i=0;i<second.size();i++){
        	if(i==0 or second[i]!=second[i-1])temp2.push_back(second[i]);
        }
        first = temp1;
        second = temp2;
        
        int mini = INT_MAX;
        for(int i=0;i<first.size();i++){
        	int up = upper_bound(second.begin(), second.end(),goal-first[i])-second.begin();
        	if(up<second.size() and up>=0){
        		mini=min(mini,abs(second[up]+first[i] - goal));
            }
        	--up;
        	if(up<second.size() and up>=0){
        		mini=min(mini,abs(second[up]+first[i] - goal));
            }
        }
        return mini;
    }
};

int main(){
	vector<int> v;
	int n;cin>>n;
	int x;cin>>x;
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		v.push_back(temp);
	}
	Solution s;
	cout<<s.minAbsDifference(v,x)<<endl;
	return 0;
}


/*
Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.
*/
