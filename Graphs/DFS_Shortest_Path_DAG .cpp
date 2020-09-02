#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs_toplogical(vector<ll> adj[],bool vis[],ll s,stack<ll> &Stack){
	vis[s]=true;
	for(ll i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false)
			dfs_toplogical(adj,vis,adj[s][i],Stack);
	}
	Stack.push(s);
}

int main(){
	//initialize
	ll n=6;
	vector<ll> adj[n];

	//map pair for storing edge weight
	map<pair<ll,ll>,ll> edgeWeight;

	//add edge adjecency list
	adj[0].push_back(1);
	edgeWeight[{0,1}]=5;
	adj[0].push_back(2);
	edgeWeight[{0,2}]=3;
	adj[1].push_back(3);
	edgeWeight[{1,3}]=6;
	adj[1].push_back(2);
	edgeWeight[{1,2}]=2;	
	adj[2].push_back(4);
	edgeWeight[{2,4}]=4;
	adj[2].push_back(5);
	edgeWeight[{2,5}]=2;
	adj[2].push_back(3);
	edgeWeight[{2,3}]=7;
	adj[3].push_back(4);
	edgeWeight[{3,4}]=-1;
	adj[4].push_back(5);
	edgeWeight[{4,5}]=-2;

	//s=source,vis[]=visted node array
	ll s=1;
	bool vis[n];
	memset(vis,false,sizeof(vis));


	//stack for storing order
	stack<ll> Stack;

	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			dfs_toplogical(adj,vis,i,Stack);
		}
	}

	//dist[]=distance from source to other node
	vector<ll> dist(n);
	for(ll i=0;i<n;i++){
		dist[i]=INT_MAX;
	}

	//distance of source from source is 0
	dist[s]=0;


	//Now we have topological order in form of stack
	// time to calculate the shortest distance 
	while(!Stack.empty()){
		ll x=Stack.top();
		if(dist[x]!=INT_MAX){
			for(ll i=0;i<adj[x].size();i++){
				if(dist[adj[x][i]]>dist[x]+edgeWeight[{x,adj[x][i]}]){
					dist[adj[x][i]]=dist[x]+edgeWeight[{x,adj[x][i]}];
				}
			}
		}
		Stack.pop();
	}

	//printing distance array
	for(ll i=0;i<n;i++){
		if(dist[i]!=INT_MAX)
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: "<<dist[i]<<endl;
		else
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: INFINITY"<<endl;
	}

	return 0;

}