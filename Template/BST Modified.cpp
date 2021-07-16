#include<bits/stdc++.h>
using namespace std;
#define int int64_t

struct node{
	int data = 0;
	node *left = NULL;
	node *right = NULL;
	int lcount = 0;
	node(int data){
		this->data = data;
	}
};

class BST{
public:z
	node *root = NULL;
	vector<node*> v;
	int size = 0;
	node *insert(node *head, int key){
		if(head == NULL){
			return new node(key);
		}
		if(key < head -> data){
			head -> left = insert(head -> left, key);
			head -> lcount ++;
		}
		else if(key > head -> data){
			head -> right = insert(head -> right, key);
		}
		return head;
	}
	bool search(node *head, int key){
		if(head == NULL){
			return false;
		}
		if(head -> data == key){
			return true;
		}
		if(key < head -> data){
			return search(head -> left, key);
		}
		return search(head -> right, key);
	}
	node *erase(node *head, int key){
		if(head == NULL){
			return head;
		}
		if(key < head -> data){
			head -> left = erase(head -> left, key);
			return head;
		}
		else if(key > head -> data){
			head -> right = erase(head -> right, key);
			return head;
		}
		else{
			if(head -> left == NULL){
				node *temp = head -> right;
				delete(head);
				return temp;
			}
			else if(head -> right == NULL){
				node *temp = head -> left;
				delete(head);
				return temp;
			}
			else{
				node *temp = minValue(root -> right);
				head -> data = temp -> data;
				head -> right = erase(head -> right, temp -> data);
				return head;
			}
		}
	}
	node *minValue(node *head){
		if(head == NULL){
			return head;
		}
		node *curr = head;
		while(curr -> left != NULL){
			curr = curr -> left;
		}
		return curr;
	}
	int minimum(node *head){
		if(head == NULL){
			cout << "empty";
			return 0;
		}
		node *curr = head;
		while(curr -> left != NULL){
			curr = curr -> left;
		}
		return curr -> data;
	}
	int maximum(node *head){
		if(head == NULL){
			cout << "empty";
			return 0;
		}
		node *curr = head;
		while(curr -> right != NULL){
			curr = curr -> right;
		}
		return curr -> data;
	}
	void inorder(node *head){
		if(head == NULL){
			return;
		}
		inorder(head -> left);
		v.push_back(head);
		inorder(head -> right);
	}
	node* balanceBST(int start, int end){
		if(start > end){
			return NULL;
		}
		int mid = (start + end) / 2;
		node *head = v[mid];
		head -> left = balanceBST(start, mid - 1);
		head -> right = balanceBST(mid + 1, end);
		return head;
	}
	node *kthSmallest(node *head, int k){
		if(head == NULL){
			return head;
		}
		int count = head -> lcount + 1;

		if(count == k){
			return head;
		}
		else if(count > k){
			return kthSmallest(head -> left, k);
		}
		else{
			return kthSmallest(head -> right, k - count);
		}
	}
};

void solve(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	BST b;


	/*insert*/
	{
		// first insert assign to root
		if(!b.search(b.root, 10)) b.size ++;
		b.root = b.insert(b.root, 10);

		// second onwards insert normally
		if(!b.search(b.root, 20)) b.size ++;
		b.insert(b.root, 20);

		if(!b.search(b.root, 12)) b.size ++;
		b.insert(b.root, 12);
	}


	/*search*/
	{
		// search a key
		cout << b.search(b.root, 122) << '\n';
	}


	/*inorder : sorted traversal of bst*/
	{
		// inorder traversal : left , root, right
		b.v.clear();
		b.inorder(b.root);
		for(auto it : b.v){
			cout << it->data << " ";
		}
		cout << '\n';
	}


	/*maximum in bst*/
	{
		cout << b.maximum(b.root) << '\n';
	}


	/*minimum in bst*/
	{
		cout << b.minimum(b.root) << '\n';
	}


	// /*k-th smallest node*/
	{
		// one based index
		for(int i = 1; i <= b.size; i ++){
			cout << b.kthSmallest(b.root, i) -> data << " ";
		}
		cout << '\n';
	}


	/*erase*/
	{
		// delete a node
		if(b.search(b.root, 12)){
			b.size --;	
			b.root = b.erase(b.root, 12);
		}
	}

	/*balanced BST*/
	{
		b.v.clear();
		b.inorder(b.root);
		b.root = b.balanceBST(0,b.v.size());
	}

}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}