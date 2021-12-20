/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/*/
-------------------------------------------------------------------------------------
/*
	M1 : 2 Pass Obvious
	O(2*n) time and O(1) space
*/
	class Solution{
	public:
	    ListNode* removeNthFromEnd(ListNode* head, int n) {
	        ListNode* node = head;
	        int N = 0;
	        while(node != nullptr){
	            N ++;
	            node = node -> next;
	        }
	        if(N == n){
	            return head -> next;
	        }
	        N -= n;
	        node = head;
	        for(int i = 0; i < N - 1; i ++){
	            node = node -> next;
	        }
	        ListNode* temp = node -> next;
	        node -> next = node -> next -> next;
	        delete temp;
	        return head;
	    }
	};
-------------------------------------------------------------------------------------
/*
	M2 : 1 Pass Slow Pointer and Fast Pointer
	O(n) time and O(1) space
*/
	class Solution{
	public:
	    ListNode* removeNthFromEnd(ListNode* head, int n) {
	        ListNode* dummy = new ListNode();
	        dummy -> next = head;
	        ListNode *slow = dummy, *fast = dummy;
	        for(int i = 0; i < n; i ++){
	            fast = fast -> next;
	        }
	        while(fast -> next != nullptr){
	            slow = slow -> next;
	            fast = fast -> next;
	        }
	        ListNode* temp = slow -> next;
	        slow -> next = slow -> next -> next;
	        delete temp;
	        return dummy -> next;
	    }
	};
-------------------------------------------------------------------------------------