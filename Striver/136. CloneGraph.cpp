/**/
/*
	M1: BFS and HashMap
	O(n) time and O(n) space
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        // bfs
        if(!node) return node;
        
        queue<Node*> q;
        vector<bool> vis;
        vis.reserve(101);
        vis.resize(101);
        map<ll, Node*> mp;
        Node* clone = new Node(node -> val);
        mp[node -> val] = clone;
        
        vis[node -> val] = 1;
        q.push(node);
        while(!q.empty()){
            ll sze = q.size();
            while(sze -- > 0){
                Node* f = q.front();
                q.pop();
                for(auto &next : f -> neighbors){
                    if(!mp.count(next -> val)){
                        mp[next -> val] = new Node(next -> val);
                    }
                    mp[f -> val] -> neighbors.push_back(mp[next -> val]); 
                    if(!vis[next -> val]){    
                        vis[next -> val] = 1;
                        q.push(next);
                    }
                }
            }
        }
        return mp[node -> val];
    }
};
/*
	M2: DFS and HashMap
	O(n) time and O(n) space
*/
class Solution {
public:
    void dfs(Node* node, vector<bool>& vis, map<ll, Node*>& mp){
        for(auto &next : node -> neighbors){
            if(!mp.count(next -> val)){
                mp[next -> val] = new Node(next -> val);
            }
            mp[node -> val] -> neighbors.push_back(mp[next -> val]); 
            if(!vis[next -> val]){    
                vis[next -> val] = 1;
                dfs(next, vis, mp);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        // bfs
        if(!node) return node;
        
        queue<Node*> q;
        vector<bool> vis;
        vis.reserve(101);
        vis.resize(101);
        map<ll, Node*> mp;
        Node* clone = new Node(node -> val);
        mp[node -> val] = clone;
        
        vis[node -> val] = 1;
        
        dfs(node, vis, mp);
        return mp[node -> val];
    }
};