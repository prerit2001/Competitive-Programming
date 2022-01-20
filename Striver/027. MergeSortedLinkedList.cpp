/*https://leetcode.com/problems/merge-two-sorted-lists/*/
----------------------------------------------------------------------------
/*
    M1 : Entirely New Linked List with Dummy Node
    O(n1 + n2) time and O(n1 + n2) space 
*/
    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode dummy(INT_MIN);
            ListNode *tail = &dummy;
            
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    tail->next = l1;
                    l1 = l1->next;
                } else {
                    tail->next = l2;
                    l2 = l2->next;
                }
                tail = tail->next;
            }

            tail->next = l1 ? l1 : l2;
            return dummy.next;
        }
    };
----------------------------------------------------------------------------
/*
    M2 : Inplace Solution
    O(n1 + n2) time and O(1) Auxilary space
*/
    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == nullptr) return l2;
            if(l2 == nullptr) return l1;
            if(l1 -> val > l2 -> val) swap(l1, l2);
            ListNode* res = l1;
            while(l1 != nullptr and l2 != nullptr){
                ListNode* temp = nullptr;
                while(l1 != nullptr and l1 -> val <= l2 -> val) {
                    temp = l1;
                    l1 = l1 -> next;
                }
                temp -> next = l2;
                swap(l1, l2);
            }
            return res;
        }
    };
----------------------------------------------------------------------------