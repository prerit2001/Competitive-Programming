/*https://www.lintcode.com/problem/850*/
--------------------------------------------------------------------------
/*
	M1: Map Lookup - start ++, end --, prefix sum - line sweep algorithm
	O(nlogn) time and O(n) space
*/
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
class Solution {
public:
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        map<int, int> intervalsPoint;
        for(vector<int> &cur: schedule){
            int len = cur.size();
            for(int i = 0; i < len; i += 2){
                int left = cur[i];
                int right = cur[i + 1];
                intervalsPoint[left] += 1;
                intervalsPoint[right] -= 1;
            }
        }
        int preSum = 0;
        for(auto &it: intervalsPoint){
            it.second += preSum;
            preSum = it.second;
        }
        bool underConsideration = 0;
        int lastCounter = -1;
        vector<Interval> ans;
        for(auto &it: intervalsPoint){
            if(underConsideration == 0){
                if(it.second == 0){
                    lastCounter = it.first;
                }
                else{
                    if(lastCounter != -1){
                        Interval curIntv(lastCounter, it.first);
                        ans.push_back(curIntv);
                    }
                    underConsideration = 1;
                }
            }
            else{
                if(it.second == 0){
                    underConsideration = 0;
                    lastCounter = it.first;
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};
--------------------------------------------------------------------------
/*
	M2: Priority Queue Lookup - push {start, 0}, push {end, 1}, deal with top 2 elements at one
	O(nlogn) time and O(n) space
*/
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        vector<Interval> result;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;
        for (int j = 0; j < schedule.size(); j++) {
            for (int i = 0; i < schedule[j].size(); i += 2) {
                heap.push(make_pair(schedule[j][i], 0));
                heap.push(make_pair(schedule[j][i + 1], 1));
            }
        }
        
        int count = 0;
        while (heap.size() > 1) {
            pair<int, int> left = heap.top();
            heap.pop();
            pair<int, int> right = heap.top();
            if (left.second == 0) {
                count += 1;
            }
            else {
                count -= 1;
            }
            if (left.second == 1 && right.second == 0) {
                if (count == 0) {
                    result.push_back(Interval(left.first, right.first));
                }
            }
        }
        
        return result;
    }
};
--------------------------------------------------------------------------