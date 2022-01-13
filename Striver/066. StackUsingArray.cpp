/*https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1#*/

//Function to push an integer into the stack.
void MyStack :: push(int a)
{
    //increasing the top pointer and pushing the integer at that position.
    top++;
    arr[top]=a;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    
    //if stack is empty, we return -1 else we return the top element.
    if(top==-1)
        return -1;
    int x=arr[top];
    top--;
    
    return x;
}