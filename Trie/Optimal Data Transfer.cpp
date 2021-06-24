#include<bits/stdc++.h>
using namespace std;
#define int int64_t

/* NOTE : - For Case of Binary String Replace All ('a' to '0') and (2 to 2); */
struct Node{
	bool end; // end of string
	int prefix_length; // length of prefix
	Node* next[2];
	Node(){
		end = false;
		prefix_length = 0;
		for(int i = 0; i < 2; i ++){
			next[i] = NULL;
		}	
	}
};

class TRIE{
public:
	void insert(string s, Node* head){
		Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - '0'] == NULL){
				temp -> next[s[i] - '0'] = new Node();
			}
			temp -> next[s[i] - '0'] -> prefix_length = (temp -> prefix_length) + 1;
			temp = temp -> next[s[i] - '0'];
		}
		temp -> end = true;
	}
	bool search(string s, Node* head){
		Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - '0'] == NULL){
				return false;
			}
			temp = temp -> next[s[i] - '0'];
		}
		return temp -> end == true;
	}
	int max_common_prefix(string s, Node *head){
		Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - '0'] == NULL){
				return temp -> prefix_length;
			}
			temp = temp -> next[s[i] - '0'];
		}
		return s.size();
	}
	int total_nodes(Node *head){
		if(head == NULL) return 0;
		int ans = 1;
		for(int i = 0; i < 2; i ++){
			ans += total_nodes(head -> next[i]); // memoise it if neeeded
		}
		return ans;
	}
};

void solve(){
	int n,m; cin >> n >> m;
	TRIE trie;
	Node *head = new Node();
	int ans = 0;
	for(int i = 0; i < n; i ++){
		string s; cin >> s;
		ans += m - trie.max_common_prefix(s,head);
		trie.insert(s,head);
	}
	cout << ans << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}