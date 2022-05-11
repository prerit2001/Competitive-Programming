/*
    Basic PBDS
*/

#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    // Ordered set declared with name o_set
    ordered_set<int> o_set;

    // insert function to insert in
    // ordered set same as SET STL
    o_set.insert(5);
    o_set.insert(1);
    o_set.insert(2);

    // Finding the second smallest element
    // in the set using * because
    // find_by_order returns an iterator
    cout << *(o_set.find_by_order(1)) << endl;

    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4) << endl;

    // Finding the count of elements less
    // than or equal to 4 i.e. strictly less
    // than 5 if integers are present
    cout << o_set.order_of_key(5) << endl;

    // Deleting 2 from the set if it exists
    if (o_set.find(2) != o_set.end()) o_set.erase(o_set.find(2));

    // Now after deleting 2 from the set
    // Finding the second smallest element in the set
    cout << *(o_set.find_by_order(1)) << endl;

    // Finding the number of
    // elements strictly less than k=4
    cout << o_set.order_of_key(4) << endl;

    return 0;
}

/*
    Advanced PBDS
*/


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// must define all parameters in case of pairs or more in cmp else annoying it will lead to WA
template <class T> struct cmp {
    bool operator() (T a, T b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

template <class T> using ordered_set = tree<T, null_type, cmp<T>, rb_tree_tag, tree_order_statistics_node_update>;

class SORTracker {
    int i;
    ordered_set<pair<ll,string>> s;    
public:
    SORTracker() 
    { i = 0; }
    
    void add(string name, int score) 
    { s.insert({score,name}); }
    
    string get() 
    { return s.find_by_order(i++)->second; }
};

// to use all function
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int t = 0;

ordered_set me;
...
me.insert({x, t++});
me.erase(me.lower_bound({x, 0}));
cout << me.order_of_key({x, 0}) << "\n";