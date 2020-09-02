#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(vector<ll> adj[],bool vis[],ll s){
	vis[s]=true;
	cout<<s<<" ";
	for(ll i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false){
			dfs(adj,vis,adj[s][i]);
		}
	}
}

int main(){
	//initialize
	ll n=7;
	vector<ll> adj[n];

	//add edge adjecency list
	adj[0].push_back(4);
	adj[0].push_back(1);
	adj[2].push_back(1);
	adj[2].push_back(3);	
	adj[5].push_back(4);
	adj[6].push_back(4);
	adj[4].push_back(0);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[3].push_back(2);	
	adj[4].push_back(5);
	adj[4].push_back(6);

	//s=source,vis[]=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));
	vis[s]=true;

	cout<<"Source is: "<<s<<"\n";

	dfs(adj,vis,s);

	//for disconnected components
	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			dfs(adj,vis,i);
		}
	}

	return 0;
}