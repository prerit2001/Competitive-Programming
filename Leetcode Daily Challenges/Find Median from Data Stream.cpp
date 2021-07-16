// ordered multiset

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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */