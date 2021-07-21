// linked list

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        if(head == NULL){
            return head;
        }
        node* past = nullptr;
        node* present = head;
        node* future = nullptr;
        node* temp = head;
        for(int i = 0; i < k; i ++){
            if(temp == NULL){
                return head;
            }
            temp = temp -> next;
        }
        if(head -> next != NULL){
            future = head -> next;
        }
        for(int i = 0; i < k; i ++){
            present -> next = past;
            past = present;
            present = future;
            if(future != NULL)
                future = future -> next;
        }
        
        head -> next = reverseKGroup(present, k);
        return past;
    }
};