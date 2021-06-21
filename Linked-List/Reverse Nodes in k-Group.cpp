// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#define node ListNode

class Solution {
public:
    node* reverseKGroup(node* head, int k) {
        if(head == NULL) return head;
        node *prev = NULL, *curr = head, *next = head -> next;
        int cnt = 0;
        
        node* temp = curr;
        
        int check = k;
        while(temp != NULL and --check>=0){
            temp = temp -> next;
        }
        
        if(check>0) return curr;
        
        while(curr != NULL and cnt++ < k){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next !=NULL)
                next = next->next;
        }
        
        if( curr != NULL)
            head -> next = reverseKGroup(curr, k);
        
        return prev;
    }
};