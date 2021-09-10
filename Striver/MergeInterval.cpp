/*https://leetcode.com/problems/merge-intervals/*/
/*
	M1 : Use Extra Store array and increment start val and decrement end val 
		and then prefix sum .
	O(n or 10000) time and O(n or 10000) space .
*/

    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        vector<int> store(10005, 0);
        vector<int> single(10005, 0);
        for(auto it : a){
            store[it[0]] ++;
            store[it[1]] --;
            if(it[0] == it[1]) single[it[0]] = 1;
        }
        for(int i = 1; i < 10005; i ++){
            store[i] += store[i-1];
        }
        for(int i = 0; i < 10005; i ++){
            if(store[i] > 0){
                int start = i;
                while(i < 10005){
                    if(store[i] == 0) break;
                    i ++;
                }
                ans.push_back({start, i});
            }
            else if(single[i] == 1){
                ans.push_back({i,i});
            }
        }
        return ans;
    }
/*
	M2 : Sort the array according to start value then do a linear check
	O(nlogn) time and O(n) extra space
*/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0) {
            return mergedIntervals; 
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; 
        
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]); 
            } else {
                mergedIntervals.push_back(tempInterval); 
                tempInterval = it; 
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals; 
    }