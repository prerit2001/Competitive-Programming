/*
	Inorder -> left root right
	Preorder -> root left right
	Postorder -> left rignt root
*/
/*
	M1: Recursion
	O(n) time and O(1) space + O(H) recursive call stack
*/
	#include<bits/stdc++.h>
	using namespace std;
	struct Node{
		int val;
		Node *left, *right;
		Node(int val){
			this -> val = val;
			this -> left = NULL;
			this -> right = NULL;
		}
	};
	void Postorder(Node *root){
		if(root == NULL) return;
		Postorder(root -> left);
		Postorder(root -> right);
		cout << root -> val << " ";
	}
	int main(){
		Node *root = new Node(1);
		root -> left = new Node(2);
		root -> right = new Node(3);
		root -> left -> left = new Node(4);
		root -> left -> right = new Node(5);

		cout << "Postorder Traversal : ";
		Postorder(root);
	}
/*
	M2: Stack
	O(n) time and O(H) space
*/
	#include<bits/stdc++.h>
	using namespace std;
	struct Node{
		int val;
		Node *left, *right;
		Node(int val){
			this -> val = val;
			this -> left = NULL;
			this -> right = NULL;
		}
	};
	void Postorder(Node *root){
		if(root == NULL) return;
		stack<Node*> s;
		stack<Node*> out;
		s.push(root);
		while(!s.empty()){
			Node *curr = s.top();
			s.pop();
			out.push(curr);
			if(curr -> left){
				s.push(curr -> left);
			}
			if(curr -> right){
				s.push(curr -> right);
			}
		}
		while(!out.empty()){
			cout << out.top() -> val << " ";
			out.pop();
		}
	}
	int main(){
		Node *root = new Node(1);
		root -> left = new Node(2);
		root -> right = new Node(3);
		root -> left -> left = new Node(4);
		root -> left -> right = new Node(5);

		cout << "Postorder Traversal : ";
		Postorder(root);
	}