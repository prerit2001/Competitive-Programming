
class Solution {
public:
    void dfsTopo(int cur, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& topo){
        vis[cur] = true;
        for(auto &it: adj[cur]){
            if(!vis[it]){
                dfsTopo(it, adj, vis, topo);
            }
        }
        topo.push(cur);
    }
    vector<int> genrateTopo(int k, vector<vector<int>>& rowConditions){
        
        stack<int> topo;
        vector<bool> vis(k + 1, false);
        vector<vector<int>> adj(k + 1);
        for(int i = 0; i < rowConditions.size(); i ++){
            adj[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for(int i = 1; i <= k; i ++){
            if(!vis[i]){
                dfsTopo(i, adj, vis, topo);
            }
        }
        vector<int> toposort;
        int index = 0;
        vector<int> pos(k + 1);
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            pos[top] = index ++;
            toposort.push_back(top);
        }
        
        // check if graph is DAG else topo does not exists
        for(int i = 1; i <= k; i ++){
            for(auto &it: adj[i]){
                if(pos[i] > pos[it]){
                    return {};
                }
            }
        }
        return toposort;
        
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> rowtopo = genrateTopo(k, rowConditions);
        vector<int> coltopo = genrateTopo(k, colConditions);
        
        if(rowtopo.size() == 0 or coltopo.size() == 0){
            return {};
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        vector<int> indexHash(k + 1);
        for(int i = 0; i < k; i ++){
            indexHash[coltopo[i]] = i; 
        }
        
        for(int i = 0; i < k; i ++){
            ans[i][indexHash[rowtopo[i]]] = rowtopo[i];
        }
        
        return ans;
    
    }
};