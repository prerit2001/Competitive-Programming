// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) {
         // your code goes here
        unordered_set<int> s;
        Node* curr = head;
        
        auto deletenode = [&](Node* ptr){
            s.insert(ptr->data);
            while(ptr->next!=NULL and s.count(ptr->next->data)){
                ptr -> next = ptr -> next -> next;
            }
        };
        while(curr!=NULL){
            deletenode(curr);
            curr = curr -> next;
        }
        
        return head;
    }
};
