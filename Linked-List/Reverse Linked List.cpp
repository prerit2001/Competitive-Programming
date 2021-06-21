// https://leetcode.com/problems/reverse-linked-list/

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


class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = NULL, *next = NULL, *prev = NULL;
        
        curr = head;
        if(head != NULL)
            next = curr -> next;
        prev = NULL;
        
        while(curr != NULL){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next !=NULL)
                next = next->next;
        }
        return prev;
    }
};

class Solution2 {
public:
    
    ListNode* go(ListNode* curr){
        if(curr == NULL or curr -> next == NULL) return curr;
        ListNode* newHead = go(curr->next);
        curr -> next -> next = curr;
        curr -> next = NULL;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        return go(head);
    }
};