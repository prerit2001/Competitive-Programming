// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root == NULL) return root;
   // Your code here
   priority_queue<Node*,vector<Node*>,compare> pq;
   set<Node*> vis;
   Node* ans = NULL;
   Node* traverse = NULL;
   Node* curr1 = root;
   while(curr1!=NULL){
       vis.insert(curr1);
       pq.push(curr1);
       curr1 = curr1 -> next;
   }
   while(!pq.empty()){
       Node* curr = pq.top();
       pq.pop();
       if(curr -> next != NULL and !vis.count(curr->next)){
           vis.insert(curr->next);
           pq.push(curr->next);
       }
       if(curr -> bottom != NULL and !vis.count(curr->bottom)){
           vis.insert(curr->bottom);
           pq.push(curr->bottom);
       }
       if(ans != NULL){
           Node* new_node = new Node(curr -> data);
           traverse -> bottom = new_node;
           traverse = traverse -> bottom;
       }
       else{
           Node* new_node = new Node(curr -> data);
           ans = new_node;
           traverse = ans;
       }
   }
   return ans;
}