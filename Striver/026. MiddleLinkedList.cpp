/*https://leetcode.com/problems/middle-of-the-linked-list/*/
-----------------------------------------------------------------------------
/*
	M1 : Convert Linked list into Array/Vector
	O(n) time and O(n) space
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};
-----------------------------------------------------------------------------
/*
	M2 : 2 pass count size (number of nodes)
	O(2*n) time and O(1) space 
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while (temp->next != NULL)
            temp = temp->next, n ++;
        n /= 2;
        while(n --){
        	head = head -> next;
        }
        return head;
    }
};
-----------------------------------------------------------------------------
/*
	M3 : 1 Pass Slow and Fast Pointers
	O(n) time and O(1) space
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
-----------------------------------------------------------------------------