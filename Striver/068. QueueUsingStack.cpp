/*https://leetcode.com/problems/implement-queue-using-stacks/*/
------------------------------------------------------------------------------------------
/* 
    Approach #1 (Two Stacks) 
    Push - O(n) per operation, Pop - O(1) per operation.
*/
public void push(int x) {
    if (s1.empty())
        front = x;
    while (!s1.isEmpty())
        s2.push(s1.pop());
    s2.push(x);
    while (!s2.isEmpty())
        s1.push(s2.pop());
}
public void pop() {
    s1.pop();
    if (!s1.empty())
        front = s1.peek();
}

------------------------------------------------------------------------------------------
/*
    Approach #2 (Two Stacks) Push - O(1) per operation, Pop - Amortized O(1) per operation.
    Time complexity: Amortized O(1), Worst-case O(n)
*/
public void push(int x) {
    if (s1.empty())
        front = x;
    s1.push(x);
}
public void pop() {
    if (s2.isEmpty()) {
        while (!s1.isEmpty())
            s2.push(s1.pop());
    }
    s2.pop();    
}
------------------------------------------------------------------------------------------