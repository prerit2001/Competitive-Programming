/*
	M1 : Recursion
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
	map<int, pair<int,int>> mp;
	void TopView(Node *root, int level, int horizontal_scale){
		if(root == NULL) return;
		if(!mp.count(horizontal_scale)){
			mp[horizontal_scale] = {level, root -> val};
		}
		else{
			if(mp[horizontal_scale].first > level){
				mp[horizontal_scale] = {level, root -> val};
			}
		}
		TopView(root -> left, level + 1, horizontal_scale - 1);
		TopView(root -> right, level + 1, horizontal_scale + 1);
	}
	int main(){
		Node *root = new Node(20);
	    root->left = new Node(8);
	    root->right = new Node(22);
	    root->left->left = new Node(5);
	    root->left->right = new Node(3);
	    root->right->left = new Node(4);
	    root->right->right = new Node(25);
	    root->left->right->left = new Node(10);
	    root->left->right->right = new Node(14);

		cout << "TopView : ";
		TopView(root,0,0);
		for(auto it : mp){
			cout << it.second.second << " ";
		}
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
	map<int, pair<int,int>> mp;
	void TopView(Node *root){
		if(root == NULL) return;
		queue<pair<Node*,int>> q;
		q.push({root,0});
		int level = 0;
		while(!q.empty()){
			int sze = q.size();
			while(sze -- > 0){
				Node* curr = q.front().first;
				int horizontal_scale = q.front().second;
				q.pop();
				if(!mp.count(horizontal_scale)){
					mp[horizontal_scale] = {level, curr -> val};
				}
				else{
					if(mp[horizontal_scale].first > level){
						mp[horizontal_scale] = {level, curr -> val};
					}
				}
				if(curr -> left != NULL) q.push({curr -> left, horizontal_scale - 1});
				if(curr -> right != NULL) q.push({curr -> right, horizontal_scale + 1});
			}
			level ++;
		}
	}
	int main(){
		Node *root = new Node(20);
	    root->left = new Node(8);
	    root->right = new Node(22);
	    root->left->left = new Node(5);
	    root->left->right = new Node(3);
	    root->right->left = new Node(4);
	    root->right->right = new Node(25);
	    root->left->right->left = new Node(10);
	    root->left->right->right = new Node(14);

		cout << "TopView : ";
		TopView(root);
		for(auto it : mp){
			cout << it.second.second << " ";
		}
	}