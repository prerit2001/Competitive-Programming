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
	void Preorder(Node *root){
		if(root == NULL) return;
		cout << root -> val << " ";
		Preorder(root -> left);
		Preorder(root -> right);
	}
	int main(){
		Node *root = new Node(1);
		root -> left = new Node(2);
		root -> right = new Node(3);
		root -> left -> left = new Node(4);
		root -> left -> right = new Node(5);

		cout << "Preorder Traversal : ";
		Preorder(root);
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
	void Preorder(Node *root){
		if(root == NULL) return;
		stack<Node*> s;
		while(root != NULL || !s.empty()){
			
			while(root != NULL){
				cout << root -> val << " ";
				if(root -> right) s.push(root -> right);
				root = root -> left;
			}

			if(!s.empty()){
				root = s.top();
				s.pop();
			}
		}
	}
	int main(){
		Node *root = new Node(1);
		root -> left = new Node(2);
		root -> right = new Node(3);
		root -> left -> left = new Node(4);
		root -> left -> right = new Node(5);

		cout << "Preorder Traversal : ";
		Preorder(root);
	}