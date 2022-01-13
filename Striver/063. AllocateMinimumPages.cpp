/*https://www.interviewbit.com/problems/allocate-books/*/
------------------------------------------------------------------
/*
	M1: Genrate all possible valid divergents
	O(2^n) time and O(n) space
*/
------------------------------------------------------------------
/*
	M2 : UpsideDown Binary Search
	O(nlogn) time and O(1) space 
*/
	int Solution::books(vector<int> &A, int B) {
	    int n = A.size();
	    if(n < B){
	        return -1;
	    }
	    function<bool(int)> isPossible = [&](int X){
	        int cur = 0;
	        int div = 1;
	        for(int i = 0; i < n; i ++){
	            cur += A[i];
	            if(cur > X){
	                div ++;
	                cur = A[i];
	                if(cur > X){
	                    return false;
	                }
	            }
	        }
	        return div <= B;
	    };
	    int low = 1, high = 1e10 + 5;
	    while(low < high){
	        int mid = (low) + (high - low) / 2;
	        bool ok = isPossible(mid);
	        if(ok){
	            high = mid;
	        }
	        else{
	            low = mid + 1;
	        }
	    }
	    return low;
	}
------------------------------------------------------------------