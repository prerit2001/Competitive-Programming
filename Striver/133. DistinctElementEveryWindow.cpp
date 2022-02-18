/*https://www.interviewbit.com/problems/distinct-numbers-in-window/discussion/c/distinct-numbers-in-window/*/
/*
	M1: Hashing Lookup Table
	O(n) time and O(n) space
*/
vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int n = A.size();
    vector<int> ans;
    for(int i = 0; i < n; i ++){
        mp[A[i]] ++;
        if(i >= B) {
            mp[A[i - B]] --;
            if(mp[A[i - B]] == 0){
                mp.erase(A[i - B]);
            }
        }
        if(i >= B - 1){
            ans.push_back(mp.size());
        }
    }
    return ans;
}
