// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        // floyd cycle detection
        Node* walker = head;
        Node* runner = head;
        Node* checksum = NULL;
        while(runner->next!=NULL && runner->next->next!=NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner){
                checksum = walker;
                break;
            }
        }
        // have loop
        if(checksum!=NULL){
            struct Node* ptr1 = checksum;
            struct Node* ptr2 = checksum;
        
            // Count the number of nodes in loop
            unsigned int k = 1, i;
            while (ptr1->next != ptr2) {
                ptr1 = ptr1->next;
                k++;
            }
        
            // Fix one pointer to head
            ptr1 = head;
        
            // And the other pointer to k nodes after head
            ptr2 = head;
            for (i = 0; i < k; i++)
                ptr2 = ptr2->next;
        
            /*  Move both pointers at the same pace,
              they will meet at loop starting node */
            while (ptr2 != ptr1) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        
            // Get pointer to the last node
            while (ptr2->next != ptr1)
                ptr2 = ptr2->next;
        
            /* Set the next node of the loop ending node
              to fix the loop */
            ptr2->next = NULL;
        }
    }
};