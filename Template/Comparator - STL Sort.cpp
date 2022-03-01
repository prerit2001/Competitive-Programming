// CUSTOM SORTING ARRAY ------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    Job arr[n];

    struct comparator cmp;
    sort(arr, arr + n, cmp);

    return 0;
}
// CUSTOM SORTING VECTOR ------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

struct comparator{
    bool operator()(Job a, Job b){
        return a.dead < b.dead;
    }  
};

int main(){

    vector<Job> arr = { { 6, 8, 1 }, { 1, 9, 1 }, { 2, 4, 1 }, { 4, 7, 1 } };

    struct comparator cmp;
    sort(arr.begin(), arr.end(), cmp);

    return 0;
}
// CUSTOM SET COMPARATOR ----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

struct comparator{
    bool operator()(Job a, Job b){
        return a.dead < b.dead;
    }  
};

int main(){

    vector<Job> arr = { { 6, 8, 1 }, { 1, 9, 1 }, { 2, 4, 1 }, { 4, 7, 1 } };

    set<Job, comparator> s(arr.begin(), arr.end());

    for(auto &it: s){
        cout << it.dead << ' ';
    }
    cout << '\n';

    return 0;
}
// PRIORITY QUEUE ------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

struct comparator{
    bool operator()(Job a, Job b){
        return a.dead < b.dead; // if you want <, do a > and vice versa ???
    }  
};

int main(){

    priority_queue<Job, vector<Job>, comparator> pq;

    return 0;
}