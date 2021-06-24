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
};

void solve(){
	Node* head = new Node();
	TrieBinary trie;
	vector<int> v = {10,15,16,20,30};
	for(int i = 0; i < v.size(); i ++){
		trie.insert(v[i],head);
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	
}