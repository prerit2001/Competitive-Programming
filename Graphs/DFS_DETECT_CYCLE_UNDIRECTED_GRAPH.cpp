#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(vector<ll> adj[],bool vis[],ll s,ll parent){
	vis[s]=true;
	for(ll i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false){
			if(dfs(adj,vis,adj[s][i],s)==true){
				return true;
			}
		}
		else if(adj[s][i]!=parent){
			return true;
		}
	}
	return false;	
}

int main(){
	//initialize
	ll n=5;
	vector<ll> adj[n];

	//add edge adjecency list
	adj[1].push_back(0);
	adj[0].push_back(1);
	adj[2].push_back(0);
	adj[0].push_back(2);	
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[3].push_back(4);
	adj[4].push_back(3);	

	//s=source,vis[]=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));
	vis[s]=true;

	cout<<"Source is: "<<s<<"\n";

	bool flag=false;

	//maitain a parent varible so that it avoid cases like ( 1 <-> 2 ) to be a cycle
	ll parent=-1;
	if(dfs(adj,vis,s,parent)==true){
		flag=true;
	}

	//for disconnected components
	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			if(dfs(adj,vis,s,parent)==true){
				flag=true;
			}
			vis[i]=true;
		}
	}

	cout<<"Graph does "<<( !flag ? "not have" : "have" ) <<" a cycle";  

	return 0;
}