/*https://www.codingninjas.com/codestudio/problems/span-of-ninja-coin_1475049*/
-------------------------------------------------------------------------------------
/*
	M1: Brute Force
	O(n^2) time and O(1) space
*/
	vector<int> findSpans(vector<int> &price) {
	    //  Size of array/list ‘price’.
	    int n = price.size();

	    //  Make an array/list ‘result’ of size ‘n’ and fill it with 0.
	    vector<int> result(n);

	    for(int i = 0; i < n; i++) {
	        int j = i;
	        //  Find span of Ninja coin on day 'i'.
	        while(j >= 0 && price[j] <= price[i]) {
	            result[i] += 1;
	            j -= 1;
	        }
	    }

	    return result;
	}
-------------------------------------------------------------------------------------
/*
	M2: Monotonic Decreasing Stack 
	O(n) time and O(1) space
*/
	vector<int> findSpans(vector<int> &prices) {
	stack<pair<int, int>> st;
	    vector<int> ans;
	    for(auto &price: prices){
	        int res = 1;
	        while(!st.empty() and st.top().first <= price){
	            res += st.top().second;
	            st.pop();
	        }
	        st.push({price, res});
	        ans.push_back(res);
	    }
	    return ans;
	}
-------------------------------------------------------------------------------------