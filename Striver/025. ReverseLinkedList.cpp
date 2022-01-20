/*https://leetcode.com/problems/reverse-linked-list/*/
-----------------------------------------------------------------------------
/*
	M1 : Recursion
	O(n) time and O(1) space + O(n) recusion call stack
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};
-----------------------------------------------------------------------------
/*
	M2 : Interative 3 pointes
	O(n) time and O(1) space
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* past = nullptr;
        ListNode* curr= nullptr;
        ListNode* upcoming = nullptr;
        if(head == nullptr) return head;
        curr = head;
        upcoming = curr -> next;
        while(curr != nullptr){
            curr -> next = past;
            past = curr;
            curr = upcoming;
            if(upcoming != nullptr) upcoming = upcoming -> next;
        }
        return past;
    }
};
-----------------------------------------------------------------------------