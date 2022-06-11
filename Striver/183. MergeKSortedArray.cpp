/*https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=2*/
----------------------------------------------------------------------------------------------------
/*
	M1: Gap Sort 2 at a time
	O(n * k * k) time and O(1) soace
*/
----------------------------------------------------------------------------------------------------
/*
	M2: Push Everything auxilury then sort every thing
	O(n * k * (n * k)) time and O(n * k) space
*/
----------------------------------------------------------------------------------------------------
/*
	M1: Use PQ Heaps
	O(n * k * logk) time and O(n * k) space
*/
	vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
	{
	    vector<int> result; 
	  
	    // Create a min heap to store atmost k heap nodes at a time.
	    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > minHeap; 
	  
	    for (int i = 0; i < kArrays.size(); i++)
	    {
	        minHeap.push({ kArrays[i][0], { i, 0 } }); 
	    }
	  
	    while (minHeap.empty() == false) 
	    { 
	    
	        // Remove the minimum element from the heap.
	        pair<int, pair<int, int> > curr = minHeap.top(); 
	        minHeap.pop(); 
	  
	        // i is the array number and j is the index of the removed element in the ith array.
	        int i = curr.second.first; 
	        int j = curr.second.second; 
	    
	        // Add the removed element to the output array.
	        result.push_back(curr.first); 
	  
	        // If the next element of the extracted element exists, add it to the heap.
	        if (j + 1 < kArrays[i].size())
	        {
	            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
	        }
	    } 
	  
	    // Return the output array.
	    return result; 
	}
----------------------------------------------------------------------------------------------------
