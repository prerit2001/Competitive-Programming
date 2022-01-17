/*https://leetcode.com/problems/sliding-window-maximum/*/
--------------------------------------------------------------------
/*
	M1: Brute Force
	O(n^2) time and O(1) space
*/
--------------------------------------------------------------------
/*
	M2: Hashing with Sliding Window
	O(nlogn) time and O(n) space
*/
	class Solution {
	public:
	    vector<int> maxSlidingWindow(vector<int>& a, int k) {
	        map<int,int> mp;
	        vector<int> ans;
	        for(int i = 0; i < a.size(); i ++){
	            if(i < k){
	                mp[a[i]] ++;
	            }
	            else{
	                ans.push_back((prev(mp.end())) -> first);
	                mp[a[i]] ++;
	                mp[a[i-k]] --;
	                if(mp[a[i-k]] == 0) mp.erase(a[i-k]);
	            }
	        }
	        ans.push_back((prev(mp.end())) -> first);
	        return ans;
	    }
	};
--------------------------------------------------------------------
/*
	M3: Monotonic Decreasing Qeque(Deque) with sliding Window
	O(n) time and O(n) space
*/
	vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> d; // monotonic dec queue
        int n = a.size();
        vector<int> ans;
        for(int i = 0; i < n; i ++){
            if(d.front() == i - k){
                d.pop_front();
            }
            while(d.size() > 0 and a[d.back()] <= a[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i >= k - 1){
                ans.push_back(a[d.front()]);
            }
        }
        return ans;
    }
--------------------------------------------------------------------