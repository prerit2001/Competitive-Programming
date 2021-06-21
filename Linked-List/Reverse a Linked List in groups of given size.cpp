// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL) return head;
        node *prev = NULL, *curr = head, *next = head -> next;
        int cnt = 0;
        while(curr != NULL and cnt++ < k){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next !=NULL)
                next = next->next;
        }
        if( curr != NULL)
            head -> next = reverse(curr, k);
        
        return prev;
    }
};