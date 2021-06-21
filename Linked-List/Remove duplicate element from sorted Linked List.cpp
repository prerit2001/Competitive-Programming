// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head){
   if(head == NULL) return head;
   auto deletenode = [&](Node* ptr){
       while(ptr->next!=NULL and ptr->data == ptr->next->data){
           ptr -> next = ptr -> next -> next;
       }   
   };
   Node* curr = head;
   while(curr != NULL){
       deletenode(curr);
       curr = curr -> next;
   }
   return head;
}