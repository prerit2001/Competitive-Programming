int N,M;

const int LIMIT = 1e5 + 5;
vector<int> adj[LIMIT];
bool vis[LIMIT];

int indegree[LIMIT] = {};
deque<int> topo_sort;

void dfs_topological_sort(int src = 0){
	vis[src] = 1;
    for( auto &i : adj[src] ){
        if( !vis[i] ){
            dfs_topological_sort( i );
        }
    }
    topo_sort.push_front( src );
}


void bfs_toplogical_sort(){
	
	queue<int> q;
	for(int i=0;i<N;i++){
		if(indegree[i] == 0 and vis[i]){
			q.push(i);
		}
	}

	int cnt = 0;
	while(!q.empty()){
		cnt ++;
		int curr = q.front();
		q.pop();
		topo_sort.push_back(curr);
		for(auto it : adj[curr]){
			if(--indegree[it] == 0){
				q.push(it);
			}
		}
	}

	// cnt must be equal to n to genrate correct topo sort else the 
	// graph must not be DAG
	
	// Graph has Cycle 
	assert(cnt == N);
}

void dfs(int src){
	vis[src] = 1;
