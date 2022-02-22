/*https://leetcode.com/problems/is-graph-bipartite/*/
/*
	M1: BFS
	O(V + E) time and O(V) space
*/
class Solution{
public:
    bool isBipartite(vector<vector<int>>& adj) {
        ll n = adj.size();
        vector<ll> color(n, 0); // 0: uncolored; 1: color A; -1: color B
        queue<ll> q;
        for(ll i = 0; i < n; i ++){
            if(color[i] == 0){
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    ll f = q.front();
                    q.pop();
                    for(auto &it: adj[f]){
                        if(color[it] == color[f]){
                            return false; // FAILED
                        }
                        else if(color[it] == 0){
                            color[it] = (color[f] == 1 ? 2 : 1);
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
/*
	M1: DFS
	O(V + E) time and O(V) space
*/
class Solution{
public:
    bool dfs(ll i, vector<vector<int>>& adj, vector<ll>& color){
        bool ok = 1;
        for(auto &it: adj[i]){
            if(color[it] == color[i]){
                return false;
            }
            if(color[it] == 0){
                color[it] = (color[i] == 1 ? 2 : 1);
                ok &= dfs(it, adj, color);
            }
        }
        return ok;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        ll n = adj.size();
        vector<ll> color(n, 0); // 0: uncolored; 1: color A; -1: color B
        for(ll i = 0; i < n; i ++){
            if(color[i] == 0){
                color[i] = 1;
                if(!dfs(i, adj, color)){
                    return false;
                }
            }
        }
        return true;
    }
};