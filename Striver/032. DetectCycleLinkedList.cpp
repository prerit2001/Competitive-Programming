/*https://leetcode.com/problems/linked-list-cycle/*/
-------------------------------------------------------------------------------
/*
	M1 : Hashmap Lookup
	O(n) time and O(n) space
*/
	bool hasCycle(ListNode *head) {
	    if(head==NULL)
	        return false;
	    unordered_map<ListNode*,int> map;
	    while(head!=NULL){
	        if(map.count(head)>0)
	            return true;
	        else
	            map[head]=1;
	        head=head->next;
	    }
	    return false;
	}
------------------------------------------------------------------------------
/*
	M2 : slow and fast pointers
	O(n/2) time and O(1) space  
*/
	class Solution {
	public:
	    bool hasCycle(ListNode *head) {
	        if(head == NULL) return false;
	        ListNode* slow = head;
	        ListNode* fast = head;
	        while(fast->next!=NULL && fast->next->next!=NULL) {
	            slow = slow->next;
	            fast = fast->next->next;
	            if(slow==fast) return true;
	        }
	        return false;
	    }
	};
-----------------------------------------------------------------------------