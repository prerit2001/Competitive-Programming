/*
	M1: BFS
	O(E + V) time and O(V) space
*/
bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited){
	queue<pair<int,int>> q;

	visited[s] = true;
	q.push({s, -1});

	while (!q.empty()) {

		int node = q.front().first;
		int par = q.front().second;
		q.pop();

		for (auto it : adj[node]) {
			if (!visited[it]) {
				visited[it] = true;
				q.push({it, node});
			}
			else if (par != it)
				return true;
		}
	}
	return false;
}
/*
	M2: DFS
	O(E + V) time and O(V) space
*/

class Solution {

public:
	bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
		vis[node] = 1; 
		for(auto it: adj[node]) {
			if(!vis[it]) {
				if(checkForCycle(it, node, vis, adj)) 
					return true; 
			}
			else if(it!=parent) 
				return true; 
		}
		
		return false; 
	}
public:
	bool isCycle(int V, vector<int>adj[]){
		vector<int> vis(V+1, 0); 
		for(int i = 0;i<V;i++) {
			if(!vis[i]) {
				if(checkForCycle(i, -1, vis, adj)) return true; 
			}
		}
		
		return false; 
	}
};