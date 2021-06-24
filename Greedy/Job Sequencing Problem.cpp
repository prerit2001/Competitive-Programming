/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool compare1(Job a, Job b){
    if(a.dead == b.dead){
        return a.profit > b.profit;
    }
    return a.dead < b.dead;
}

struct compare2{
    bool operator()(const int a, const int b){
        return a > b;
    }
};


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        // your code here
        sort(arr,arr+n,compare1);
        int maxi = 0;
        int profit = 0, ans = 0;
        priority_queue<int,vector<int>,compare2> pq;
        for(int i = 0; i < n; i ++){
            if(arr[i].dead > maxi){
                maxi = arr[i].dead;
                pq.push(arr[i].profit);
            }
            else if(pq.size() < maxi){
                pq.push(arr[i].profit);
            }
            else if(pq.size() == maxi){
                if(pq.top() < arr[i].profit){
                    pq.pop();
                    pq.push(arr[i].profit);
                }
            }
        }
        while(!pq.empty()){
            ans += 1;
            profit += pq.top();
            pq.pop();
        }
        vector<int> v(2);
        v[0] = ans,v[1] = profit;
        return v;
    } 
};