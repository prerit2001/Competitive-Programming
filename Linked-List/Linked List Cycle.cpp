// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner->next!=NULL && runner->next->next!=NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner) return true;
        }
        return false;
    }
};