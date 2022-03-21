/*https://leetcode.com/problems/implement-trie-prefix-tree/*/
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

class Trie {
public:
    Node* head;
    Trie() {
        head = new Node();
    }
    
    void insert(string s) {
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
    
    bool search(string s) {
        Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - 'a'] == NULL){
				return false;
			}
			temp = temp -> next[s[i] - 'a'];
		}
		return temp -> end == true;
    }
    
    bool startsWith(string s) {
        Node *temp = head;
		for(int i = 0; i < s.size(); i ++){
			if(temp -> next[s[i] - 'a'] == NULL){
				return false;
			}
			temp = temp -> next[s[i] - 'a'];
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */