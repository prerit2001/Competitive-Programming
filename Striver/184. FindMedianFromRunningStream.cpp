/*https://leetcode.com/problems/find-median-from-data-stream/*/
---------------------------------------------------------------
/*
	M1: Ordered Set
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

class MedianFinder {
public:
    /** initialize your data structure here. */
    ordered_set s;
    int cnt = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert({num,cnt++});    
    }
    
    double findMedian() {
        if(cnt&1){
            return (double)(s.find_by_order(cnt/2))->first;
        }
        else{
            return (double)(s.find_by_order((cnt-1)/2)->first + s.find_by_order(cnt/2)->first)/2;
        }
    }
};
---------------------------------------------------------------
/*
	M2: Using Two Heap
*/
class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n;
    MedianFinder() {
        pq1 = priority_queue<int>();
        pq2 = priority_queue<int, vector<int>, greater<int>>();
        n = 0;
    }
    
    void addNum(int num) {
        if(n % 2 == 0){
            if(pq1.size() == 0 or pq1.top() >= num) pq1.push(num);
            else pq2.push(num), pq1.push(pq2.top()), pq2.pop();
        }
        else{
            if(pq1.top() <= num) pq2.push(num);
            else pq2.push(pq1.top()), pq1.pop(), pq1.push(num);
        }
        n ++;
    }
    
    double findMedian() {
        if(n % 2 == 0){
            return ( pq1.top() + pq2.top() ) / 2.0;
        }
        else{
            return pq1.top();
        }
    }
    
};
---------------------------------------------------------------