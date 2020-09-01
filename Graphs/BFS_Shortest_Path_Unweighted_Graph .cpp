#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs(vector<ll> adj[],bool vis[],vector<ll> &dist,ll s){
	queue<ll> q;
	q.push(s);
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		for(ll i=0;i<adj[x].size();i++){
			if(vis[adj[x][i]]==false){
				if(dist[adj[x][i]]>dist[x]+1){
					dist[adj[x][i]]=dist[x]+1;
				}
				vis[adj[x][i]]=true;
				q.push(adj[x][i]);
			}
		}
	}
}

int main(){

	//initialize
	ll n=6;
	vector<ll> adj[n];

	//add edge adjecency list
	adj[0].push_back(4);
	adj[0].push_back(2);
	adj[0].push_back(1);
	adj[3].push_back(1);
	adj[2].push_back(3);	
	adj[2].push_back(4);
	adj[5].push_back(4);
	adj[5].push_back(3);

	adj[4].push_back(0);
	adj[2].push_back(0);
	adj[1].push_back(0);
	adj[1].push_back(3);
	adj[3].push_back(2);	
	adj[4].push_back(2);
	adj[4].push_back(5);
	adj[3].push_back(5);

	//s=source,vis[]=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));
	vis[s]=true;

	cout<<"Source is: "<<s<<"\n";

	//dist[]=distance from source to other node
	vector<ll> dist(n);
	for(ll i=0;i<n;i++){
		dist[i]=INT_MAX;
	}

	//distance of source from source is 0
	dist[s]=0;

	//bfs 
	bfs(adj,vis,dist,s);

	//printing distance array
	for(ll i=0;i<n;i++){
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: "<<dist[i]<<endl;
	}


	return 0;
}