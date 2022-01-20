/*https://practice.geeksforgeeks.org/problems/flattening-a-linked-list*/
--------------------------------------------------------------------------------------
/*
	M1 : Merge 2 Linked List at a time recursively
	O(Number of Nodes) time and O(1) space
*/
	node* merge(node* a, node* b){
	    node* dummy = new node(0);
	    node* head = dummy;
	    while(a != nullptr and b != nullptr){
	        if(a -> data < b -> data){
	            dummy -> bottom = a;
	            dummy = dummy -> bottom;
	            a = a -> bottom;
	        }
	        else{
	            dummy -> bottom = b;
	            dummy = dummy -> bottom;
	            b = b -> bottom;
	        }
	    }
	    if(a != nullptr) dummy -> bottom = a;
	    if(b != nullptr) dummy -> bottom = b;
	    return head -> bottom;
	}

	node *flatten(node *root){
	    if(root == nullptr or root -> next == nullptr) return root;
	    root -> next = flatten(root -> next);
	    root = merge(root, root -> next);
	    return root;
	}
--------------------------------------------------------------------------------------
