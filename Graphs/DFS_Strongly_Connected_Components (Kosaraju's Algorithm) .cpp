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
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[1].push_back(3);	
	adj[3].push_back(4);

	//vis[]=visted node array
	bool vis[n];
	memset(vis,false,sizeof(vis));


	//stack for storing order of finish time
	stack<ll> Stack;

	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			dfs_toplogical(adj,vis,i,Stack);
		}
	}

	//now we have stack storing reverse order of finish time
	//now create reverse graph
	vector<ll> adj_transpose[n];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<adj[i].size();j++){
			adj_transpose[adj[i][j]].push_back(i);
		}
	}
	memset(vis,false,sizeof(vis));

	//printing answer
	ll strongly_connected_components=0;
	while(!Stack.empty()){
		ll x=Stack.top();
		Stack.pop();
		if(vis[x]==false)
		{
			dfs(adj_transpose,vis,x);
			cout<<"\n";
			strongly_connected_components++;
		}
	}

	cout<<"No. of Strongly Connected Components are "<<strongly_connected_components<<endl;

	return 0;

}