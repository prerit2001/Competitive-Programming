/*https://www.codingninjas.com/codestudio/problems/complete-string_2687860*/
------------------------------------------------------------------------------
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
void insert(trie *root, string& s){
    for(char &c: s){
        if(!root -> next[c - 'a']){
            root -> next[c - 'a'] = new trie();
        }
        root = root -> next[c - 'a'];
    }
    root -> end = true;
}
bool check(trie *root, string& s){
    for(char &c: s){
        root = root -> next[c - 'a'];
    	if(!root -> end){
            return false;
        }
    }
    return true;
}
string completeString(int n, vector<string> &a){
    trie* head = new trie();
    string ans = "";
    for(auto &s: a){
        insert(head, s);
    }
    for(auto &s: a){
     	if(check(head, s)){
            if(ans.size() < s.size()){
                ans = s;
            }
            else if(ans.size() == s.size()){
                if(ans > s){
                    ans = s;
                }
            }
        }   
    }
    if(ans == ""){
        return "None";
    }
    return ans;
}
----------------------------------------------------------------------------