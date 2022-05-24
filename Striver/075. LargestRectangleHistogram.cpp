/*https://leetcode.com/problems/largest-rectangle-in-histogram*/
-----------------------------------------------------------------
/*
	M1: Brute Force -> find next/prev smaller linearly
	O(n^2) time and O(1) space
*/
-----------------------------------------------------------------
/*
	M2: Stack 2 Pass Solution
	O(n) time and O(n) space
*/
	int largestRectangleArea(vector<int>& h) {
        stack<ll> sL, sR;
        ll n = h.size();
        vector<ll> L(n), R(n);
        for(ll i = n - 1; i >= 0; i --){
            while(sR.size() > 0 and h[sR.top()] >= h[i]){
                sR.pop();
            }
            if(sR.size() > 0) R[i] = sR.top();
            else R[i] = n;
            sR.push(i);
        }
        for(ll i = 0; i < n; i ++){
            while(sL.size() > 0 and h[sL.top()] >= h[i]){
                sL.pop();
            }
            if(sL.size() > 0) L[i] = sL.top();
            else L[i] = -1;
            sL.push(i);
        }
        ll ans = 0;
        for(ll i = 0; i < n; i ++){
            ans = max(ans, h[i] * (R[i] - L[i] - 1));
        }
        return ans;
    }
-----------------------------------------------------------------
/*
	M3: One Pass Solution
	O(n) time and O(1) space
*/
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; 
        int maxA = 0; 
        int n = heights.size(); 
        for(int i = 0;i<=n;i++) {
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop(); 
                int width; 
                if(st.empty()) width = i; 
                else width = i - st.top() - 1; 
                
                // cout << i << " " << width << " " << height << endl; 
                maxA = max(maxA, width * height); 
            }
            st.push(i); 
        }
        return maxA;
    }
-----------------------------------------------------------------