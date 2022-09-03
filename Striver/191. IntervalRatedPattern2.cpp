/*https://leetcode.com/problems/my-calendar-i/*/
-------------------------------------------------------------
/*
	M1: brute ad-hoc
	O(n^2) and O(1) space
*/
-------------------------------------------------------------
/*
	M2: ordered set with upper bound
	O(n^logn) time and O(n) space
*/
class MyCalendar {
public:
    set<pair<int, int>> bookings;
    MyCalendar() {
        bookings.clear();
    }
    
    bool book(int start, int end) {
        if(bookings.size() == 0){
            bookings.insert({start, end});
            return true;
        }
        auto ub = bookings.upper_bound({start, -1});
        if(ub == bookings.begin()){
            if(ub -> first >= end){
                bookings.insert({start, end});
                return true;
            }
            return false;
        }
        if(ub == bookings.end() or ub -> first >= end){
            ub --;
            if(ub -> second <= start){
                bookings.insert({start, end});
                return true;
            }   
        }
        return false;
    }
};
-------------------------------------------------------------
 