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
	ll n=5;
	vector<ll> adj[n];

	//add edge adjecency list
	adj[1].push_back(2);
	adj[0].push_back(2);
	adj[0].push_back(1);
	adj[3].push_back(4);


	//vis[]=visted node array
	bool vis[n];
	memset(vis,false,sizeof(vis));

	//connected components
	ll count_connected_components = 0;
	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			dfs(adj,vis,i);
			vis[i]=true;
			count_connected_components++;
			cout<<"\n";
		}
	}

	cout<<"Count of connected components : "<<count_connected_components<<"\n";

	return 0;
}