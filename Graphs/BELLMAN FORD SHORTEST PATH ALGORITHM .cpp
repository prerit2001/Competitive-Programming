#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> bellman_ford(vector<ll> adj[],map<pair<ll,ll>,ll> &edgeWeight,ll n,ll s){
	vector<ll> dist(n,INT_MAX);
	dist[s]=0;
	for(ll j=0;j<n-1;j++){
    	for(auto it=edgeWeight.begin();it!=edgeWeight.end();it++){
    		if(dist[it->first.first]+it->second<dist[it->first.second]){
    			dist[it->first.second]=dist[it->first.first]+it->second;
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
	edgeWeight[{0,1}]=1;
	adj[0].push_back(2);
	edgeWeight[{0,2}]=4;
	adj[1].push_back(2);
	edgeWeight[{1,2}]=-3;
	adj[2].push_back(3);
	edgeWeight[{2,3}]=3;
	adj[1].push_back(3);
	edgeWeight[{1,3}]=2;


	//s=source,vis[]=visted node array
	ll s=0;
	bool vis[n];
	memset(vis,false,sizeof(vis));

	//bellman's ford algorithm
	vector<ll> dist=bellman_ford(adj,edgeWeight,n,s);

	//check if there is negative weight cycle
	bool flag=false;
	for(auto it=edgeWeight.begin();it!=edgeWeight.end();it++){
		if(dist[it->first.first]+it->second<dist[it->first.second]){
    			flag=true;
		}
	}

	if(flag){
		cout<<"Graph contains negative weight cycle...";
		return 0;
	}

	for(ll i=0;i<n;i++){
		if(dist[i]!=INT_MAX)
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: "<<dist[i]<<endl;
		else
		cout<<"Distance of node "<<i<<" from source "<<s<<" is: INFINITY"<<endl;
	}

	return 0;
}