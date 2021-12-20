/*https://leetcode.com/problems/linked-list-cycle-ii/*/
----------------------------------------------------------------------------------
/*
	M1 : Use Hashmap Lookup
	O(n or nlogn) time and O(n) space
*/
	ListNode* hasCycle(ListNode *head) {
	    if(head==NULL)
	        return false;
	    unordered_map<ListNode*,int> map;
	    while(head!=NULL){
	        if(map.count(head)>0){
	            return head;
	        }
	        else
	            map[head]=1;
	        head=head->next;
	    }
	    return false;
	}
----------------------------------------------------------------------------------
/*
	M2 : Slow and Fast Pointer + Intersection of Two Linked List
	O(n) time and O(1) space

	steps -> 
		-> Determine if there exists a cycle, return nullptr if not, 
			otherwise return the ListNode where the fast pointer and 
			the slow pointer meet, denoted as tail.
		-> Get intersection of the two linked list: head --> ... --> tail 
			and tail->next --> ... --> tail
*/
	ListNode *detectCycle(ListNode *head) {
	    if (head == NULL || head->next == NULL)
	        return NULL;
	    
	    ListNode *slow  = head;
	    ListNode *fast  = head;
	    ListNode *entry = head;
	    
	    while (fast->next && fast->next->next) {
	        slow = slow->next;
	        fast = fast->next->next;
	        if (slow == fast) {                      // there is a cycle
	            while(slow != entry) {               // found the entry location
	                slow  = slow->next;
	                entry = entry->next;
	            }
	            return entry;
	        }
	    }
	    return NULL;                                 // there has no cycle
	}
----------------------------------------------------------------------------------