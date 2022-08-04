/*https://leetcode.com/problems/implement-stack-using-queues/*/
-------------------------------------------------------------------
/*Approach #1 (Two Queues, push - O(1), pop O(n))*/
public void push(int x) {
    q1.add(x);
    top = x;
}
public void pop() {
    while (q1.size() > 1) {
        top = q1.remove();
        q2.add(top);
    }
    q1.remove();
    Queue<Integer> temp = q1;
    q1 = q2;
    q2 = temp;
}
-------------------------------------------------------------------
/*Approach #2 (Two Queues, push - O(n), pop O(1) )*/
public void push(int x) {
    q2.add(x);
    top = x;
    while (!q1.isEmpty()) {                
        q2.add(q1.remove());
    }
    Queue<Integer> temp = q1;
    q1 = q2;
    q2 = temp;
}
public void pop() {
    q1.remove();
    if (!q1.isEmpty()) {
    	top = q1.peek();
    }
}
-------------------------------------------------------------------
/*Approach #2 (One Queues, push - O(n), pop O(1) )*/
public void push(int x) {
    q1.add(x);
    int sz = q1.size();
    while (sz > 1) {
        q1.add(q1.remove());
        sz--;
    }
}
public void pop() {
    q1.remove();
}
-------------------------------------------------------------------