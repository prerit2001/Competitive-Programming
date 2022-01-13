/*https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1#*/

//Function to push an integer into the Queue.
void MyQueue :: push(int a)
{
    //increasing the top pointer and pushing the integer at that position.
    front++;
    arr[front]=a;
}

//Function to remove an item from top of the Queue.
int MyQueue :: pop()
{
    
    //if Queue is empty, we return -1 else we return the top element.
    if(back==front)
        return -1;
    int x=arr[back];
    back++;
    
    return x;
}