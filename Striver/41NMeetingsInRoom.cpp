/*https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#*/
--------------------------------------------------------------------------------------
/*
	M1: Genrate all subsequence
	O(2^n) time and O(n) space
*/
--------------------------------------------------------------------------------------
/*
	M2: Sort according to the end time
	O(nlogn) time and O(n) space
*/
	class Solution{
	    public:
	    int maxMeetings(int start[], int end[], int n){
	        vector<pair<int, int>> v(n);
	        for(int i = 0; i < n; i ++){
	            v[i] = {start[i], end[i]};
	        }
	        int ans = 0;
	        sort(v.begin(), v.end(), [&](pair<int, int> x, pair<int, int> y){
	            if(x.second < y.second) return 1;
	            else{
	                if(x.second == y.second){
	                    if(x.first < y.first) return 1;
	                }
	            }
	            return 0;
	        });
	        int lastDone = -1;
	        for(int i = 0; i < n; i ++){
	            if(v[i].first > lastDone){
	                ans ++;
	                lastDone = v[i].second;
	            }
	        }
	        return ans;
	    }
	};
--------------------------------------------------------------------------------------