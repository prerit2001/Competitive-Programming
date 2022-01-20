/*https://leetcode.com/problems/rotate-list/*/
--------------------------------------------------------------------------------------
/*
	M1 : Ad-Hoc
	O(n) time and O(1) space
*/
	#define node ListNode
	class Solution {
	public:
	    ListNode* rotateRight(ListNode* head, int k) {
	        if(head == nullptr) return head;
	        int n = 0;
	        node* root = head;
	        while(root != nullptr) root = root -> next, n ++;
	        k = k % n;
	        if(n <= 1 or k == 0) return head;
	        node* slow = head, *fast = head;
	        while(k -- > 0){
	            fast = fast -> next;
	        }
	        while(fast != nullptr and fast -> next != nullptr){
	            slow = slow -> next;
	            fast = fast -> next;
	        }
	        node* temp = slow -> next;
	        slow -> next = nullptr;
	        fast -> next = head;
	        return temp;
	    }
	};
--------------------------------------------------------------------------------------