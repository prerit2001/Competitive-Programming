/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock/*/
-------------------------------------------------------------------------
/*
	M1 : Brute Force
	O(n^2) time and O(1) space
*/
------------------------------------------------------------------------
/*
	M2 : Time Optimised
	O(n) time and O(n) space
*/
	class Solution {
	public:
	    int maxProfit(vector<int>& a) {
	        ll n=prices.size();  //cin>>n;
	        int mini[n] = {},maxi[n] = {};
	        mini[0] = a[0], maxi[n-1]=a[n-1];
	        for(int i=1;i<n;i++){
	            mini[i] = min(mini[i-1],a[i]);
	            maxi[n-i-1] = max(maxi[n-i],a[n-i-1]);
	        } 
	        int ans = -1;
	        for(int i=1;i<n;i++){
	            ans = max(ans,maxi[i]-mini[i-1]);
	        }	
	        return max(ans,0ll);
	    }
	};
------------------------------------------------------------------------
/*
	M3 : Single Pass Approach
	O(n) time and O(1) space
*/
	class Solution {
	    public:
	    int maxProfit(int prices[]) {
	        int minprice = INT_MAX;
	        int maxprofit = 0;
	        for (int i = 0; i < prices.size(); i++) {
	            if (prices[i] < minprice)
	                minprice = prices[i];
	            else if (prices[i] - minprice > maxprofit)
	                maxprofit = prices[i] - minprice;
	        }
	        return maxprofit;
	    }
	}
------------------------------------------------------------------------