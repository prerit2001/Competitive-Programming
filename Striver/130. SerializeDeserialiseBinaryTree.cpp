/**/
/*
	M1: DFS
	O(n) time and O(n) call stack
*/
	/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
	class Codec {
	public:

	    string dfs_encode(TreeNode* root){
	        if(root == nullptr) return ""; 
	        string s = "";
	        s += to_string(root -> val) + ',';
	        if(root -> left == nullptr){
	            s += "N,";
	        }
	        else{
	            s += dfs_encode(root -> left);
	        }
	        if(root -> right == nullptr){
	            s += "N,";
	        }
	        else{
	            s += dfs_encode(root -> right);
	        }
	        return s;
	    }
	    
	    // Encodes a tree to a single string.
	    string serialize(TreeNode* root) {
	        string encode = dfs_encode(root);
	        // preorder travdersal
	        cout << encode;
	        return encode;
	    }
	    
	    int idx = 0;
	    TreeNode* dfs_decode(string s){
	        if(idx >= s.size() - 1){
	            return nullptr;
	        }
	        if(s[idx] == 'N'){
	            idx ++;
	            return nullptr;
	        }
	        string curr = "";
	        while(idx < s.size()){
	            if(s[idx] == ',') break;
	            curr += s[idx ++];
	        }
	        TreeNode* head = new TreeNode(stoi(curr));
	        idx ++;
	        head -> left = dfs_decode(s);
	        idx ++;
	        head -> right = dfs_decode(s);
	        return head;
	    }

	    // Decodes your encoded data to tree.
	    TreeNode* deserialize(string data) {
	        idx = 0;
	        
	        if(data == "") return nullptr;
	        
	        TreeNode* root = dfs_decode(data);
	        
	        return root;
	        
	    }
	};
/*
	M2: BFS
	O(n) time and O(n) space
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode = "";
        if(root == nullptr){
            return encode;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sze = q.size();
            while(sze -- > 0){
                TreeNode* front = q.front();
                q.pop();
                if(front != nullptr){
                    q.push(front->left);
                    q.push(front->right);
                    encode += to_string(front -> val);
                    encode += ",";
                }
                else{
                    encode += '#';
                    encode += ",";
                }
            }
        }
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0){
            return nullptr;
        }
        int i = 0;
        string elem = "";
        while(i < n and data[i] != ','){
            elem += data[i];
            i ++;
        }
        i ++;
        TreeNode* root = new TreeNode(stoll(elem));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sze= q.size();
            while(sze -- > 0){
                TreeNode* front = q.front();
                q.pop();
                if(i < n and data[i] != '#'){
                    elem = "";
                    while(i < n and data[i] != ','){
                        elem += data[i];
                        i ++;
                    }
                    i ++;
                    front -> left = new TreeNode(stoll(elem));
                    q.push(front -> left);
                }
                else{
                    i += 2;
                    front -> left = nullptr;
                }
                if(i < n and data[i] != '#'){
                    elem = "";
                    while(i < n and data[i] != ','){
                        elem += data[i];
                        i ++;
                    }
                    i ++;
                    front -> right = new TreeNode(stoll(elem));
                    q.push(front -> right);
                }
                else{
                    i += 2;
                    front -> right = nullptr;
                }          
            }
        }
        return root;
    }
};
