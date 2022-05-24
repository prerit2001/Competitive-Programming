/*https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292*/
------------------------------------------------------------------------------------------
struct trie{
	trie *next[26];
    bool end;
    trie(){
        for(int i = 0; i < 26; i ++){
            next[i] = nullptr;
        }
        end = false;
    }
};
void insert(trie *root, string s){
    for(char &c: s){
        if(!root -> next[c - 'a']){
            root -> next[c - 'a'] = new trie();
        }
        root = root -> next[c - 'a'];
    }
}
int cnt(trie *root){
    int ans = 1;
    for(int i = 0; i < 26; i ++){
        if(root -> next[i]){
            int var = cnt(root -> next[i]);
            ans += var;
        }
    }
    return ans;
}
int countDistinctSubstrings(string &s)
{
    int n = s.size();
    trie* head = new trie();
    for(int i = 0; i < n; i ++){
        insert(head, s.substr(i));
    }
    return cnt(head);
}
------------------------------------------------------------------------------------------