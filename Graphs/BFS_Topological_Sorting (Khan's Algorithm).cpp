#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs_topological(vector<ll> adj[],vector<ll> &indegree){
	queue<ll> q;
	for(ll i=0;i<indegree.size();i++){
		if(indegree[i]==0)q.push(i);
	}
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		cout<<x<<" ";
		for(ll i=0;i<adj[x].size();i++){
			indegree[adj[x][i]]--;
			if(indegree[adj[x][i]]==0){
				q.push(adj[x][i]);
			}
		}
	}
}

int main(){
	//initialize
	ll n=5;
	vector<ll> adj[n];

	//indegree vector initialize
	vector<ll> indegree(n);
	//default value of indegre elements is 0

	//add edge adjecency list
	adj[0].push_back(3);
	indegree[3]++;
	adj[0].push_back(2);
	indegree[2]++;
	adj[1].push_back(3);
	indegree[3]++;
	adj[1].push_back(4);
	indegree[4]++;

	//s=source,vis=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));
	vis[s]=true;

	bfs_topological(adj,indegree);
}