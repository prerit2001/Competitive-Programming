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

	//add edge adjecency list
	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);	
	adj[2].push_back(3);
	adj[3].push_back(1);

	//vis[]=visted node array
	bool vis[n];
	memset(vis,false,sizeof(vis));


	//stack for storing order
	stack<ll> Stack;

	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			dfs_toplogical(adj,vis,i,Stack);
		}
	}

	//printing topological order
	while(!Stack.empty()){
		cout<<Stack.top()<<" ";
		Stack.pop();
	}

	return 0;

}