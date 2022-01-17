// O(n^2) time O(1) space
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;


void printStack(stack<ll> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
}

void insertAtCorrectPosition(ll store, stack<ll>& s){
    if(s.size() > 0 and s.top() < store){
        ll elem = s.top();
        s.pop();
        insertAtCorrectPosition(store, s);
        s.push(elem);
    }
    else{
        s.push(store);
        return;
    }
}

void sortStack(stack<ll>& s){
    if(s.size() == 1){
        return;
    }
    ll store = s.top();
    s.pop();
    sortStack(s);
    insertAtCorrectPosition(store, s);
}


int main() {
    
    stack<ll> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack(s);

    sortStack(s);

    printStack(s);

    return 0;
}
