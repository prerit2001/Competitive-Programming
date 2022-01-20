/*https://leetcode.com/problems/add-two-numbers*/
--------------------------------------------------------------------------------------
/*
	M1 : Elementary Math
	O(max(n, m)) time and O(max(n, m)) space
*/
	class Solution {
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        ListNode* dummyHead = new ListNode(0);
		    ListNode* p = l1,* q = l2,* curr = dummyHead;
		    int carry = 0;
		    while (p != null || q != null) {
		        int x = (p != null) ? p -> val : 0;
		        int y = (q != null) ? q -> val : 0;
		        int sum = carry + x + y;
		        carry = sum / 10;
		        curr -> next = new ListNode(sum % 10);
		        curr = curr -> next;
		        if (p != null) p = p -> next;
		        if (q != null) q = q -> next;
		    }
		    if (carry > 0) {
		        curr.next = new ListNode(carry);
		    }
		    return dummyHead -> next;
	    }
	};
--------------------------------------------------------------------------------------
/*
	M2 : Space Efficient
	O(max(n, m)) and O(1) Auxilary Space
*/
	class Solution {
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        ListNode* root = l1;
	        int carry = 0;
	        ListNode* prev = nullptr;
	        while(l1 != nullptr and l2 != nullptr){
	            l1 -> val = l1 -> val + l2 -> val + carry;
	            carry = l1 -> val / 10;
	            l1 -> val %= 10;
	            prev = l1;
	            l1 = l1 -> next;
	            l2 = l2 -> next;
	        }
	        while(l1 != nullptr){
	            l1 -> val = l1 -> val + carry;
	            carry = l1 -> val / 10;
	            l1 -> val %= 10;
	            prev = l1;
	            l1 = l1 -> next;
	        }
	        if(l2 != nullptr) prev -> next = l2;
	        while(l2 != nullptr){
	            l2 -> val = l2 -> val + carry;
	            carry = l2 -> val / 10;
	            l2 -> val %= 10;
	            prev = l2;
	            l2 = l2 -> next;
	        }
	        if(carry > 0){
	            string s = to_string(carry);
	            for(char &c : s){
	                ListNode* temp = new ListNode(int(c-'0'));
	                prev -> next = temp;
	                prev = temp;
	            }
	        }
	        return root;
	    }
	};
--------------------------------------------------------------------------------------