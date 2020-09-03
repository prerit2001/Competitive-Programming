#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dijkstra(vector<ll> adj[],map<pair<ll,ll>,ll> &edgeWeight,ll n,ll s){
	vector<ll> dist(n,INT_MAX);
	dist[s]=0;
	vector<ll> fin(n,false);
	for(ll i=0;i<n-1;i++){
		ll min = INT_MAX, min_index; 
 
		for (ll v = 0; v < n ; v++) 
        	if (fin[v] == false && dist[v] < min) 
            	min = dist[v], min_index = v; 

    	fin[min_index]=true;

    	for(ll i=0;i<adj[min_index].size();i++){
    		if(fin[adj[min_index][i]]==false && dist[adj[min_index][i]]>dist[min_index]+edgeWeight[{min_index,adj[min_index][i]}]){
        		dist[adj[min_index][i]]=dist[min_index]+edgeWeight[{min_index,adj[min_index][i]}];
        	}
    	}
	}
	return dist;
}

int main(){
	//initialize
	ll n=4;
	vector<ll> adj[n];

	//map pair for storing edge weight
	map<pair<ll,ll>,ll> edgeWeight;

	//add edge adjecency list
	adj[0].push_back(1);
	edgeWeight[{0,1}]=50;
	adj[1].push_back(0);
	edgeWeight[{1,0}]=50;
	adj[0].push_back(2);
	edgeWeight[{0,2}]=100;
	adj[2].push_back(0);
	edgeWeight[{2,0}]=100;
	adj[1].push_back(2);
	edgeWeight[{1,2}]=30;
	adj[2].push_back(1);
	edgeWeight[{2,1}]=30;	
	adj[1].push_back(3);
	edgeWeight[{1,3}]=200;
	adj[3].push_back(1);
	edgeWeight[{3,1}]=200;
	adj[2].push_back(3);
	edgeWeight[{2,3}]=20;
	adj[3].push_back(2);
	edgeWeight[{3,2}]=20;


	//s=source,vis[]=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));

	//dijkstra algo
	vector<ll> dist=dijkstra(adj,edgeWeight,n,s);

	for(ll i=0;i<n;i++){
		if(dist[i]!=INT_MAX)
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: "<<dist[i]<<endl;
		else
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: INFINITY"<<endl;
	}

	return 0;
}