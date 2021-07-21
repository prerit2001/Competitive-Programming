#include<bits/stdc++.h>
using namespace std;
#define int int64_t

struct Node{
	Node* next[2];
	Node(){
		for(int i = 0; i < 2; i ++){
			next[i] = NULL;
		}	
	}
};

class TrieBinary{
public:
	void insert(int num, Node* head){
		Node* temp = head;
		for(int i = 31; i >= 0; i --){
			int bit = (num >> i) & 1;
			if(temp -> next[bit] == NULL){
				temp -> next[bit] = new Node();
			}
			temp = temp -> next[bit];
		}
	}
	int max_XOR_pair(int num, Node* head){
		Node* temp = head;
		int ans = 0;
		for(int i = 31; i >= 0; i --){
			int bit = (num >> i) & 1;
			int opposite_bit = bit ^ 1;
			if(temp -> next[opposite_bit] != NULL){
				ans += (1 << i);
				temp = temp -> next[opposite_bit];
			}
			else{
				temp = temp -> next[bit];
			}
		}
		return ans;
	}
};

void solve(){
	Node* head = new Node();
	TrieBinary trie;
	vector<int> v = {3,10,5,25,2,8};
	for(int i = 0; i < v.size(); i ++){
		trie.insert(v[i],head);
	}
	int max_XOR_pair = 0;
	for(int i = 0; i < v.size();i ++){
		max_XOR_pair = max(max_XOR_pair,trie.max_XOR_pair(v[i],head));
	}
	cout << max_XOR_pair << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	
}