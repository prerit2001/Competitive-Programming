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

void insertAtBottom(ll store, stack<ll>& s){
    if(s.size() == 0){
        s.push(store);
        return;
    }
    ll elem = s.top();
    s.pop();
    insertAtBottom(store, s);
    s.push(elem);
}

void reverseStack(stack<ll>& s){
    if(s.size() == 1){
        return;
    }
    ll store = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(store, s);
}

int main() {
    
    stack<ll> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack(s);

    reverseStack(s);

    printStack(s);

    return 0;
}
