/*https://leetcode.com/problems/find-median-from-data-stream/*/
/*
	M1: Policy Based Data Structure - Ordered Set
	O(logn) per query and O(n) space
*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> struct cmp {
    bool operator() (T a, T b) {
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

template <class T> 
using ordered_set = tree<T, null_type, cmp<T>, rb_tree_tag, tree_order_statistics_node_update>;
class MedianFinder {
public:
    int n;
 	ordered_set<pair<int, int>> s;    
    MedianFinder() {
        n = 0;
        s.clear();
    }
    void addNum(int num) {
        s.insert({num, n ++});
    }
    double findMedian() {
        if(n % 2 == 1){
        	return 1.0 * s.find_by_order((n) / 2) -> first;
        }
        else{
        	long a = s.find_by_order((n - 1) / 2) -> first;
        	long b = s.find_by_order((n) / 2) -> first;
        	return (a + b) / 2.0;
        }
        return -1;
    }
};
/*
	M2: Using 2 Priority Queue
	O(logn) per query and O(n) space
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
