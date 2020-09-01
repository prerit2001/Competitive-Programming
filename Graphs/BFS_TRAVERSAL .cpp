#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(vector<ll> adj[],bool vis[],ll s){
	queue<ll> q;
	q.push(s);
	while(!q.empty()){
		ll x=q.front();
		cout<<x<<" ";
		q.pop();
		for(ll i=0;i<adj[x].size();i++){
			if(vis[adj[x][i]]==false){
				cout<<adj[x][i]<<" ";
				vis[adj[x][i]]=true;
			}
		}
	}
}

int main(){

	//initialize
	ll n=5;
	vector<ll> adj[n];

	//add edge adjecency list
	adj[0].push_back(4);
	adj[0].push_back(3);
	adj[0].push_back(1);
	adj[3].push_back(2);
	adj[2].push_back(0);

	//s=source,vis=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));
	vis[s]=true;

	//bfs
	bfs(adj,vis,s);

	//for disconnected components
	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			bfs(adj,vis,i);
			vis[i]=true;
		}
	}

	
}