/*https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1*/
-------------------------------------------------------------------------------------
/*
	M1: Memoization
	O(n*deadline) time and O(n*deadline) space
*/
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

struct comparator{
    bool operator()(Job a, Job b){
        return a.dead < b.dead;
    }  
};

const int M = 1e5 + 5;
Job a[M];
pair<int, int> dp[M][105];

class Solution {
public:
    pair<int, int> JobChoice(int i, int n, int nextSlotAvailable = 1){
    	if(i >= n){
    		return {0, nextSlotAvailable - 1}; // since next_Slot_available - 1 == number of job done
    	}
    	if(dp[i][nextSlotAvailable] != pair<int, int>(-1, -1)){
    		return dp[i][nextSlotAvailable];
    	}
    	pair<int, int> choice1 = {0, 0};
    	if(a[i].dead >= nextSlotAvailable){
    		choice1 = JobChoice(i + 1, n, nextSlotAvailable + 1);
    		choice1 = {a[i].profit + choice1.first, choice1.second};
    	}
    	pair<int, int> choice2 = JobChoice(i + 1, n, nextSlotAvailable);
    	if(choice1.first > choice2.first){
    		return dp[i][nextSlotAvailable] = choice1;
    	}
    	return dp[i][nextSlotAvailable] = choice2;
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        struct comparator cmp;
        sort(arr, arr + n, cmp);
        for(int i = 0; i < n; i ++){
        	a[i] = arr[i];
        	for(int j = 0; j < 105; j ++){
        		dp[i][j] = {-1, -1};
        	}
        }
        pair<int, int> ans = JobChoice(0, n);
        return {ans.second, ans.first};
    } 
};

-------------------------------------------------------------------------------------
/*
	M2: Greedy
	O(n*deadline) and O(n) space
*/
class Solution {
public:
    //function used for sorting all jobs according to decreasing profit.
    static bool comparison(Job a, Job b) { 
    	return (a.profit > b.profit); 
    } 
    
    vector<int> JobScheduling(Job arr[], int n) { 
        int res = 0, count = 0;
        
    	//sorting all jobs according to decreasing order of profit.
        sort(arr, arr+n, comparison); 
        
        //array to store result (Sequence of jobs). 
        int result[n];
    	//boolean array to keep track of free time slots.
        bool slot[n]; 
        
        for (int i=0; i<n; i++) 
          slot[i] = false; 
      
    	//iterating through all given jobs.
      for (int i=0; i<n; i++) { 
        	//finding a free slot for current job (Note that we start 
        	//from the last possible slot). 
       for (int j=min(n, arr[i].dead)-1; j>=0; j--) { 
        		//if free slot is found, we add current job to result array
        		//and make the current slot occupied. 
          if (slot[j]==false) { 
             result[j] = i;  
             slot[j] = true; 
             break; 
         } 
     } 
 } 
 
 for (int i=0; i<n; i++) { 
    	    //if slot is occupied, we update the counter and //add its profit in final result.
   if (slot[i]) {
       count++;
       res += arr[result[i]].profit;
   }
}

vector<int> ans;
ans.push_back(count);
ans.push_back(res);
return ans;
} 
};
-------------------------------------------------------------------------------------
/*
	M3: Priority Queue
	O(nlogn) time and O(n) space	
*/
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

struct comparator1{
    bool operator()(Job a, Job b){
        return a.dead < b.dead;
    }  
};

struct comparator2{
	bool operator()(int firstElem, int secondElem){
		return firstElem > secondElem;
	}
};

class Solution 
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        struct comparator1 cmp;
        sort(arr, arr + n, cmp);


        priority_queue<int, vector<int>, comparator2> pq; 
        int slotBookedTillNow = 0;
        for(int i = 0; i < n; i ++){
        	Job& cur = arr[i];
        	if(cur.dead > slotBookedTillNow){
        		slotBookedTillNow ++;
        		pq.push(cur.profit);
        	}
        	else if(cur.dead == slotBookedTillNow){
        		if(pq.top() < cur.profit){
        			pq.pop();
        			pq.push(cur.profit);
        		}
        	}
        }

        int profitEarned = 0;
        int numberOfJobDone = 0;
        while(pq.size() > 0){
        	profitEarned += pq.top();
        	numberOfJobDone ++;
        	pq.pop();
        }

        return {numberOfJobDone, profitEarned};

    } 
};
-------------------------------------------------------------------------------------
/*
	M4: DSU
	O(nlogn) time and O(n) space
*/
/*
struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

struct comparator{
    bool operator()(Job x, Job y){
        if(x.profit == y.profit)
            return x.dead < y.dead;
        return x.profit > y.profit;
    }
};

class DSU{
    vector<int> parent;
    int n;
public:
    DSU(int n){
        this -> n  = n;
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find_set(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
    void union_set(int x, int y){
        parent[x] = find_set(x);
        parent[y] = find_set(y);
        if(parent[x] == parent[y]){
            return;
        }
        parent[y] = parent[x];
    }
};

class Solution 
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        struct comparator cmp;
        sort(arr, arr + n, cmp);
        
        DSU dsu(101);
        int ans = 0;    
        int job = 0;

        for(int i = 0; i < n; i ++){
    // check if it is possible to take this into consideration
            
            int parent_I = dsu.find_set(arr[i].dead);
            if(parent_I == 0){
                continue;
            }
            
            job += 1;
            ans += arr[i].profit;
            dsu.union_set(parent_I - 1, parent_I);
        }
        
        return {job, ans};
    } 
};
-------------------------------------------------------------------------------------