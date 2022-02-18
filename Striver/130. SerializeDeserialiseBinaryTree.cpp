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
        if(!root) return "";
        
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};