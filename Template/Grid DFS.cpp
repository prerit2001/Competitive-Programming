int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string ds = "RLDU";

int N,M;

bool possible(int curr_x,int curr_y){
	return curr_x >= 0 and curr_x < N and curr_y >= 0 and curr_y < M;
}

void dfs(int curr_x, int curr_y){
	if(!possible(curr_x,curr_y)){
		return;
	}
	if(vis[curr_x][curr_y]){
		return;
	}
	if(s[curr_x][curr_y] != '.'){
		return;
	}
	vis[curr_x][curr_y] = true;
	for(int i=0;i<4;i++){
		int next_x = curr_x + dx[i];
		int next_y = curr_y + dy[i];
		dfs(next_x,next_y);
	}
}