#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(vector<ll> adj[],bool vis[],ll s,bool conStack[]){
	if(vis[s]==false){
		vis[s]=true;
		conStack[s]=true;
		for(ll i=0;i<adj[s].size();i++){
			if(vis[adj[s][i]]==false){
				if(dfs(adj,vis,adj[s][i],conStack)==true){
					return true;
				}
			}
			else if(conStack[adj[s][i]]==true){
				return true;
			}
	}
	}
	conStack[s]=false;
	return false;	
}

int main(){
	//initialize
	ll n=4;
	vector<ll> adj[n];

	//add edge adjecency list
	adj[0].push_back(2);
	adj[0].push_back(1);
	adj[2].push_back(1);
	adj[2].push_back(3);	
	adj[3].push_back(3);
	adj[2].push_back(0);
	
	//s=source,vis[]=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));

	//for every connected component we have to check
	//conStack[]=visting connected component elements
	bool conStack[n];
	memset(conStack,false,sizeof(conStack));


	bool flag=false;
	if(dfs(adj,vis,s,conStack)==true){
		flag=true;
	}

	//for every connected components
	for(ll i=0;i<n;i++){
		if(vis[i]==false){
			if(dfs(adj,vis,s,conStack)==true){
				flag=true;
			}
			vis[i]=true;
		}
	}

	cout<<"Graph does "<<( !flag ? "not have" : "have" ) <<" a cycle";  


	return 0;

}