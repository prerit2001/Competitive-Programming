// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int k = a.size();
        if(k == 0) return NULL;
        Node *head = NULL;
        int mini = 1e9;
        bool finish[k];
        for(int j = 0; j < k; j ++){
            if(a[j] == NULL){
                finish[j] = 1;
            }
            else{
                finish[j] = 0;
                mini = min(a[j]->val,mini);
            }
        }
        Node* root = NULL;
        for(int j = 0; j < k; j ++){
            if(finish[j] == 0 and a[j] -> val == mini){
                head = a[j];
                root = head;
                if(a[j] != NULL){
                    a[j] = a[j] -> next;
                }
                else{
                    finish[j] = 1;
                }
                break;
            }
        }
        bool flag = 1;
        int cnt = 6;
        while(flag){
            flag = 0;
            mini = 1e9;
            for(int j = 0; j < k; j ++){
                if(a[j] == NULL){
                    finish[j] = 1;
                }
                else{
                    flag = 1;
                    finish[j] = 0;
                    mini = min(a[j]->val,mini);
                }
            }
            for(int j = 0; j < k; j ++){
                if(finish[j] == 0 and a[j] -> val == mini){
                    head->next = a[j];
                    head = head -> next;
                    if(a[j] != NULL){
                        a[j] = a[j] -> next;
                    }
                    else{
                        finish[j] = 1;
                    }
                    break;
                }
            }
        }
        return root;
    }
};