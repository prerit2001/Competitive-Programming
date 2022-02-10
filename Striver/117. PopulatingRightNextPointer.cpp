/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/*/
/*
	M1: Recursion Adhoc
	O(n) time and O(1) space (suppose implicit stack space)
*/
	class Solution {
	public:
	    void inorder(Node* parent, Node* current){
	        if(current == NULL){
	            return;
	        }
	        if(parent != NULL){
	            if(parent -> right != current){
	                current -> next = parent -> right;
	            }
	            else{
	                if(parent -> next != NULL){
	                    current -> next = parent -> next -> left;
	                } 
	            }
	        }
	        inorder(current, current -> left);
	        inorder(current, current -> right);
	    }
	    Node* connect(Node* root) {
	        inorder(NULL, root);
	        return root;
	    }
	};
/*
	M2: Iterative Approach
	O(n) time and O(1) space
*/
	Node* connect(Node* root) {
        
        Node* Head = root;
        while(root != NULL){
            Node* cur = root;   // if we are at node x we will populate its child next pointer then move to its child and so on ...
            while(cur != NULL){
                if(cur -> left != NULL){
                    cur -> left -> next = cur -> right;
                }
                if(cur -> next != NULL and cur -> right != NULL){
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            root = root -> left;
        }
        
        return Head;
    }