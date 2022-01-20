/*https://leetcode.com/problems/reverse-nodes-in-k-group*/
----------------------------------------------------------------------------------
/*
    M1 : Recursion
    O(n) time and O(n) recusion call stack space
*/
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
----------------------------------------------------------------------------------
/*
    M2 : Iterative
    O(n) time and O(1) space
*/
    class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if(head==NULL||k==1) return head;
            int num=0;
            ListNode *preheader = new ListNode(-1);
            preheader->next = head;
            ListNode *cur = preheader, *nex, *pre = preheader;
            while(cur = cur->next) 
                num++;
            while(num>=k) {
                cur = pre->next;
                nex = cur->next;
                for(int i=1;i<k;++i) {
                    cur->next=nex->next;
                    nex->next=pre->next;
                    pre->next=nex;
                    nex=cur->next;
                }
                pre = cur;
                num-=k;
            }
            return preheader->next;
        }
    };
----------------------------------------------------------------------------------