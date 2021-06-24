#include<bits/stdc++.h>
using namespace std;
#define int int64_t

struct Node{
	bool end; // end of string
	int prefix_length; // length of prefix
	Node* next[26];
	Node(){
		end = false;
		prefix_length = 0;
		for(int i = 0; i < 26; i ++){
			next[i] = NULL;
		}	
	}
};

class TRIE{
public:
	void insert(string s, Node* head){
		Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - 'a'] == NULL){
				temp -> next[s[i] - 'a'] = new Node();
			}
			temp -> next[s[i] - 'a'] -> prefix_length = (temp -> prefix_length) + 1;
			temp = temp -> next[s[i] - 'a'];
		}
		temp -> end = true;
	}
	bool search(string s, Node* head){
		Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - 'a'] == NULL){
				return false;
			}
			temp = temp -> next[s[i] - 'a'];
		}
		return temp -> end == true;
	}
	int max_common_prefix(string s, Node *head){
		Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - 'a'] == NULL){
				return temp -> prefix_length;
			}
			temp = temp -> next[s[i] - 'a'];
		}
		return s.size();
	}
	int total_nodes(Node *head){
		if(head == NULL) return 0;
		int ans = 1;
		for(int i = 0; i < 26; i ++){
			ans += total_nodes(head -> next[i]); // memoise it if neeeded
		}
		return ans;
	}
};

void solve(){
	Node* head = new Node();
	TRIE trie;
	vector<string> v = {"random","temprory","temple","temp"};
	for(string &s : v){
		trie.insert(s,head);
	}
	cout << trie.search("temple",head) << endl;
	cout << trie.max_common_prefix("rain",head) << endl;
	cout << trie.total_nodes(head) << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	while(t--){
		solve();
	}
	
}