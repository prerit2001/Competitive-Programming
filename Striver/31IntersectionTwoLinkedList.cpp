/*https://leetcode.com/problems/intersection-of-two-linked-lists/*/
----------------------------------------------------------------------------------------------
/*
	M1 : Haspmap Lookup
	O(n + m) time and O(min(n, m)) space
*/
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		map<ListNode*, int> mA;
		ListNode* pA = headA;
		while (pA) {
			mA[pA]++;
			pA = pA->next;
		}
		ListNode* pB = headB;
		while (pB) {
			if (mA.find(pB) != mA.end())
				return pB;
			pB= pB->next;
		}
		return nullptr;
	}
----------------------------------------------------------------------------------------------
/*
	M2 : Difference in lenth
	O(n + m) time and O(1) space
*/
	class Solution {
	public:
	    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	        int nA = 0, nB = 0;
	        ListNode* currA = headA;
	        ListNode* currB = headB;
	        while(currA != NULL){
	            ++ nA;
	            currA = currA -> next;
	        }
	        while(currB != NULL){
	            ++ nB;
	            currB = currB -> next;
	        }
	        if(nA > nB){
	            swap(headA,headB);
	        }
	        int diff = abs(nA - nB);
	        currA = headA;
	        currB = headB;
	        while(diff-- > 0){
	            currB = currB -> next;
	        }
	        while(currA != NULL and currB != NULL){
	            if(currA == currB) return currA;
	            currA = currA -> next;
	            currB = currB -> next;
	        }
	        return NULL;
	    }
	};
	OR
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	    ListNode *ptrA = headA, *ptrB = headB;
	    while (ptrA != ptrB) { 
	        ptrA = ptrA ? ptrA->next : headB;
	        ptrB = ptrB ? ptrB->next : headA;
	    }
	    return ptrA;
	}
----------------------------------------------------------------------------------------------