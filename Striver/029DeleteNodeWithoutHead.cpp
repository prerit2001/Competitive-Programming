/*https://leetcode.com/problems/delete-node-in-a-linked-list/*/
---------------------------------------------------------------------------------
/*
	M1 : Tricky Swap current and next
	O(1) time
*/
	class Solution {
	public:
	    void deleteNode(ListNode* node) {
	        swap(node -> val, node -> next -> val);
	        ListNode* toBeDeleted = node -> next;
	        node -> next = node -> next -> next;
	        delete toBeDeleted;
	    }
	};
---------------------------------------------------------------------------------