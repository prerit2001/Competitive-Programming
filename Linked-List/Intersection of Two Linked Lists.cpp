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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int nA = 0, nB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;
        while(currA != NULL){
            ++ nA;
            currA = currA -> next;
        }
        while(currB != NULL){
            ++ nB;
            currB = currB -> next;
        }
        if(nA > nB){
            swap(headA,headB);
        }
        int diff = abs(nA - nB);
        currA = headA;
        currB = headB;
        while(diff-- > 0){
            currB = currB -> next;
        }
        while(currA != NULL and currB != NULL){
            if(currA == currB) return currA;
            currA = currA -> next;
            currB = currB -> next;
        }
        return NULL;
    }
};