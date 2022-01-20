/*https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#*/
--------------------------------------------------------------------------------------
/*
	M1: Sort according to the max profit having checksum for feasiblity
	O(n*m) time and O(m) space
*/
	// A structure to represent a job
	struct Job
	{
	   char id;  
	   int dead;    
	   int profit;  
	};

	bool comparison(Job a, Job b){
	     return (a.profit > b.profit);
	}

	void printJobScheduling(Job arr[], int n) {
	    sort(arr, arr+n, comparison);

	    int result[n]; 
	    bool slot[n]; 

	    for (int i=0; i<n; i++)
	        slot[i] = false;

	    for (int i=0; i<n; i++) {
	       for (int j=min(n, arr[i].dead)-1; j>=0; j--) {
	          if (slot[j]==false) {
	             result[j] = i;  // Add this job to result
	             slot[j] = true; // Make this slot occupied
	             break;
	          }
	       }
	    }

	    // Print the result
	    for (int i=0; i<n; i++)
	       if (slot[i])
	         cout << arr[result[i]].id << " ";
	}
--------------------------------------------------------------------------------------
/*
	M2 : DSU
	O(n) time and O(m) space

	steps -> 
		-> Sort according to the max profit.
		-> for every id check the max avaible free slot in the DSU class.
*/
	/*
	struct Job 
	{ 
	    int id;	 // Job Id 
	    int dead; // Deadline of job 
	    int profit; // Profit if job is over before or on deadline 
	};
	*/

	class DSU{
	public:
	    vector<int> parent, size;
	    int n;
	    DSU(int n){
	        this->n = n;
	        parent.resize(n);
	        size.resize(n);
	        iota(parent.begin(),parent.end(),0);
	        for (int i = 0; i < n; i ++){
	            size[i] = 1;
	        }
	    }
	    int group_size(int a){
	        int parent = find_set(a);
	        return size[parent];
	    }
	    int find_set(int a){
	        if (parent[a] == a)
	            return a;
	        return parent[a] = find_set(parent[a]);
	    }
	    int union_set(int a, int b){
	        a = find_set(a);
	        b = find_set(b);
	        if (a == b){
	            return -1;
	        }
	        parent[b] = parent[a];
	        size[a] += size[b];
	        return a;
	    }
	    void print_groups(){
	        map<int,vector<int>> group;
	        for(int i = 0; i < n; i ++){
	            group[find_set(i)].push_back(i);
	        }
	        for(auto v : group){
	            cout << v.first << " : [ ";
	            for(auto ele : v.second){
	                cout << ele << " "; 
	            }
	            cout << "]\n";
	        }
	    }
	};

	bool compare(Job a, Job b) {
	    return a.profit > b.profit;
	}

	class Solution 
	{
	    public:
	    //Function to find the maximum profit and the number of jobs done.
	    vector<int> JobScheduling(Job arr[], int n) 
	    { 
	        // your code here
	        DSU dsu(101);
	        sort(arr, arr + n, compare);
	        int profit = 0, jobDone = 0;
	        for(int i = 0; i < n; i ++){
	            int parent = dsu.find_set(arr[i].dead);
	            if(parent == 0) continue; // skip
	            dsu.union_set(parent - 1, parent);
	            profit += arr[i].profit;
	            jobDone += 1;
	        }
	        return {jobDone, profit};
	    } 
	};
--------------------------------------------------------------------------------------