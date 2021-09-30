/*
	M1 : Recusion
	O(n) time and O(1) space + O(n) Recursion Call Stack  
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
	int max_level = 0;
	void LeftView(Node *root, int level){
		if(root == NULL) return;
		if(max_level < level){
			max_level = level;
			cout << root -> val << " ";
		}
		LeftView(root -> left, level + 1);
		LeftView(root -> right, level + 1);
	}
	int main(){
		Node *root = new Node(1);
		root -> left = new Node(2);
		root -> right = new Node(3);
		root -> left -> left = new Node(4);
		root -> left -> right = new Node(5);

		cout << "LeftView : ";
		LeftView(root,1);
	}
/*
	M2 : BFS Queue
	O(n) time and O(n) space
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
	void LeftView(Node *root){
		if(root == NULL) return;
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			int sze = q.size();
			Node* curr = q.front();
			q.pop();
			cout << curr -> val << " ";
			if(curr -> left != NULL) q.push(curr -> left);
			if(curr -> right != NULL) q.push(curr -> right);
			sze --;
			while(sze -- > 0){
				curr = q.front();
				q.pop();
				if(curr -> left != NULL) q.push(curr -> left);
				if(curr -> right != NULL) q.push(curr -> right);
			}
		}
	}
	int main(){
		Node *root = new Node(1);
		root -> left = new Node(2);
		root -> right = new Node(3);
		root -> left -> left = new Node(4);
		root -> left -> right = new Node(5);

		cout << "LeftView : ";
		LeftView(root);
	}