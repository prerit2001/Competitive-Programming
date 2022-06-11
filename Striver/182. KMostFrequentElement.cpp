/*https://leetcode.com/problems/top-k-frequent-elements/*/
-------------------------------------------------------------------------------------
/*
	M1: Sort according to frequcy and return top k elems
	O(nlogn) time and O(n) space
*/
-------------------------------------------------------------------------------------
/*
	M2: Use unordered Map for frequency maitainence and then Use Heap of Size K only
	Better than O(n + klogk) time and O(n) space
*/
	class Solution {
	public:
	    vector<int> topKFrequent(vector<int>& nums, int k) {
	        unordered_map<int,int> map;
	        for(int num : nums){
	            map[num]++;
	        }
	        
	        vector<int> res;
	        // pair<first, second>: first is frequency,  second is number
	        priority_queue<pair<int,int>> pq; 
	        for(auto it = map.begin(); it != map.end(); it++){
	            pq.push(make_pair(it->second, it->first));
	            if(pq.size() > (int)map.size() - k){
	                res.push_back(pq.top().second);
	                pq.pop();
	            }
	        }
	        return res;
	    }
	};
------------------------------------------------------------------------------------
/*
	M3: Bucket Sort Super Easy
	O(n) time and O(n) space
*/
	class Solution {
	public:
	    vector<int> topKFrequent(vector<int>& nums, int k) {
	        unordered_map<int, int> cnt;
	        for (int x : nums) cnt[x] += 1;
	        
	        int n = nums.size();
	        vector<vector<int>> bucket(n+1, vector<int>());
	        for (auto [num, freq] : cnt) {
	            bucket[freq].push_back(num);
	        }
	        int bucketIdx = n;
	        vector<int> ans;
	        while (k > 0) {
	            while (bucket[bucketIdx].size() == 0) { // Skip empty bucket!
	                bucketIdx -= 1;
	            }
	            for (int x : bucket[bucketIdx]) {
	                if (k == 0) break;
	                ans.push_back(x);
	                k -= 1;
	            }
	            bucketIdx -= 1;
	        }
	        return ans;
	    }
	};
------------------------------------------------------------------------------------