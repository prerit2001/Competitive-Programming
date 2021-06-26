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
#define Node ListNode
class Solution {
public:
    
    ListNode* reverseSegment(ListNode* head){
        Node *curr = head;
        Node *prev = NULL;
        if(head -> next == NULL) return head;
        Node *next = head -> next;
        while(curr != NULL){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next != NULL)
                next = next -> next;
        }
        return prev;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        Node *curr = head;
        Node *tail = NULL;
        Node *start = NULL;
        if(head == NULL) return NULL;
        if(left == right) return head;    
        Node *prev = NULL;
        for(int i = 1; i <= right; i ++){
            if(i == right){
                tail = curr -> next;
                curr -> next = NULL;
                break;
            }
            if(i == left - 1){
                prev = curr;
            }
            if(i == left){
                start = curr;
            }
            curr = curr -> next;
        }
        
        Node* startSegment = head;
        Node* midSegment = reverseSegment(start);
        Node* endSegment = tail;
        
        if(left != 1){
            prev -> next = NULL;
            Node* temp = NULL;
            while(startSegment != NULL){
                temp = startSegment;
                startSegment = startSegment -> next;
            }
            temp -> next = midSegment;
        }
        else{
            head = midSegment;
        }
        Node* temp = NULL;
        while(midSegment != NULL){
            temp = midSegment;
            midSegment = midSegment -> next;
        }
        temp -> next = tail;
        
        return head;
    }
};