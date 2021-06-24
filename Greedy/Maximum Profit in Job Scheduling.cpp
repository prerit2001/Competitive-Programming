class Solution {
public:
    int dp[50005];
    vector<tuple<int,int,int>> v;
    int go(int curr, int n){
        if(curr == n) return 0;
        if(dp[curr] != -1) return dp[curr];
        int st = get<0>(v[curr]);
        int et = get<1>(v[curr]);
        int profit = get<2>(v[curr]);
        int next_curr = -1;
        int left = curr + 1, right = n;
        while(left < right){
            int mid = (left + right) / 2;
            if(get<0>(v[mid]) < et){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        next_curr = left;
        int choice1 = profit + go(next_curr,n);
        int choice2 = go(curr+1,n);
        return dp[curr] = max(choice1,choice2);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < st.size(); i ++){
            v.push_back({st[i],et[i],p[i]});
        }
        sort(v.begin(),v.end());
        return go(0,st.size());
    }
};