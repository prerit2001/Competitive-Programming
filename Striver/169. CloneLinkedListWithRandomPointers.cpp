/*https://leetcode.com/problems/copy-list-with-random-pointer/*/
------------------------------------------------------------------------
	/*
	// Definition for a Node.
	class Node {
	public:
	    int val;
	    Node* next;
	    Node* random;
	    
	    Node(int _val) {
	        val = _val;
	        next = NULL;
	        random = NULL;
	    }
	};
	*/

	class Solution {
	public:
	    Node* copyRandomList(Node* head) {
	        Node* dummy = new Node(0);
	        Node* ans = dummy;
	        map<Node*, Node*> mp;
	        Node* root = head;
	        while(head != nullptr){
	            dummy -> next = new Node(head -> val);
	            mp[head] = dummy -> next;
	            dummy = dummy -> next; 
	            head = head -> next;
	        }
	        head = root; 
	        while(head != nullptr){
	            if(head -> random != nullptr){
	                mp[head] -> random = mp[head -> random];
	            }
	            head = head -> next;
	        }
	        return ans -> next;
	    }
	};
-------------------------------------------------------------------------