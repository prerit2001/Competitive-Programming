/*https://www.interviewbit.com/problems/maximum-sum-combinations/*/
--------------------------------------------------------------------------
/*
	M1: Brute Force
	O(n^2) time and O(k) space
*/
--------------------------------------------------------------------------
/*
	M2: Heaps
	O(Nlogn) time and O(n) space
*/
	vector KMaxCombinations(vector& A,vector& B, int K)
	{
	    // sort both arrays A and B
	    sort(A.begin(), A.end());
	    sort(B.begin(), B.end());
	    vectorans;
	    int N = A.size();

	    // Max heap which contains tuple of the format
	    // (sum, (i, j)) i and j are the indices
	    // of the elements from array A
	    // and array B which make up the sum.
	    priority_queue > > pq;

	    // my_set is used to store the indices of
	    // the  pair(i, j) we use my_set to make sure
	    // the indices doe not repeat inside max heap.
	    set > my_set;

	    // initialize the heap with the maximum sum
	    // combination ie (A[N - 1] + B[N - 1])
	    // and also push indices (N - 1, N - 1) along
	    // with sum.
	    pq.push(make_pair(A[N - 1] + B[N - 1],
	                      make_pair(N-1, N-1)));

	    my_set.insert(make_pair(N - 1, N - 1));

	    // iterate upto K
	    for (int count=0; count > temp = pq.top();
	        pq.pop();

	        ans.push_back(temp.first);

	        int i = temp.second.first;
	        int j = temp.second.second;

	        if(i-1>=0)
	        {
	            int sum = A[i - 1] + B[j];

	        // insert (A[i - 1] + B[j], (i - 1, j))
	        // into max heap.
	        pair temp1 = make_pair(i - 1, j);

	        // insert only if the pair (i - 1, j) is
	        // not already present inside the map i.e.
	        // no repeating pair should be present inside
	        // the heap.
	        if (my_set.find(temp1) == my_set.end()) {
	            pq.push(make_pair(sum, temp1));
	            my_set.insert(temp1);
	        }
	        }

	        // insert (A[i] + B[j - 1], (i, j - 1))
	        // into max heap
	        if(j-1>=0)
	        {
	        int sum = A[i] + B[j - 1];
	        pairtemp1 = make_pair(i, j - 1);

	        // insert only if the pair (i, j - 1)
	        // is not present inside the heap.
	        if (my_set.find(temp1) == my_set.end()) {
	            pq.push(make_pair(sum, temp1));
	            my_set.insert(temp1);
	        }
	        }
	    }
	    return ans;
	}
	vector Solution::solve(vector &A, vector &B, int C) {
	    vectortemp=KMaxCombinations(A,B,C);
	    return temp;
	}
--------------------------------------------------------------------------