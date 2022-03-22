/*https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/*/
----------------------------------------------------------------------------
/*
	M1: Brute Ad-hoc
	O(n^2) time and O(n) space
*/
----------------------------------------------------------------------------
/*
	M2: Trie
	O(n * 32) time and O(n * 32) space  
*/
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
class Solution {
public:
    int findMaximumXOR(vector<int>& v) {
        Node* head = new Node();
        TrieBinary trie;
        for(int i = 0; i < v.size(); i ++){
            trie.insert(v[i],head);
        }
        int max_XOR_pair = 0;
        for(int i = 0; i < v.size();i ++){
            max_XOR_pair = max(max_XOR_pair,trie.max_XOR_pair(v[i],head));
        }
        return max_XOR_pair;
    }
};
----------------------------------------------------------------------------