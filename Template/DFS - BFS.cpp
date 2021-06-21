const int LIMIT = 1e5+5; 

vector<int> adj[LIMIT];
bool vis[LIMIT];

void bfs(int src){
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(auto it : adj[curr]){
			if(!vis[it]){
				vis[it] = true;
				q.push(it);
			}
		}
	}
}

void dfs(int src){
	vis[src] = 1;
	for(auto it : adj[src]){
		if(!vis[it]){
			dfs(it);
		}
	}
}
