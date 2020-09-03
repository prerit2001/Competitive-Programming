#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void PrimsAlgo_MST(vector<ll> adj[],bool vis[],map<pair<ll,ll>,ll> &edgeWeight,ll n,ll Parent[]){
	ll key[n]={}; // picking min edge weight
	for(ll i=0;i<n;i++){
		key[i]=INT_MAX;
	}
	key[0]=0;
	Parent[0]=-1;

	//we have n-1 edges at max
	for(ll i=0;i<n-1;i++){
		
		ll min = INT_MAX, min_index; 
 
		for (ll v = 0; v < n ; v++) 
        	if (vis[v] == false && key[v] < min) 
            	min = key[v], min_index = v; 

        vis[min_index]=true;
        for(ll i=0;i<adj[min_index].size();i++){
        	if(vis[adj[min_index][i]]==false && key[adj[min_index][i]]>edgeWeight[{min_index,adj[min_index][i]}]){
        		Parent[adj[min_index][i]]=min_index;
        		key[adj[min_index][i]]=edgeWeight[{min_index,adj[min_index][i]}];
        	}
        }    
	}
}

int main(){

	//initialize
	ll n=4;
	vector<ll> adj[n];

	//map pair for storing edge weight
	map<pair<ll,ll>,ll> edgeWeight;

	//add edge adjecency list
	adj[0].push_back(1);
	edgeWeight[{0,1}]=9;
	adj[0].push_back(2);
	edgeWeight[{0,2}]=10;
	adj[0].push_back(3);
	edgeWeight[{0,3}]=5;
	adj[1].push_back(2);
	edgeWeight[{1,2}]=8;	
	adj[2].push_back(3);
	edgeWeight[{2,3}]=7;
	adj[1].push_back(0);
	edgeWeight[{1,0}]=9;
	adj[2].push_back(0);
	edgeWeight[{2,0}]=10;
	adj[3].push_back(0);
	edgeWeight[{3,0}]=5;
	adj[2].push_back(1);
	edgeWeight[{2,1}]=8;	
	adj[3].push_back(2);
	edgeWeight[{3,2}]=7;
	

	//s=source,vis[]=visted node array
	bool vis[n];
	memset(vis,false,sizeof(vis));

	// storing constructed MST
	ll Parent[n]={};

	PrimsAlgo_MST(adj,vis,edgeWeight,n,Parent);

	//printing solution
	cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < n; i++) 
        cout<<Parent[i]<<" - "<<i<<" \t"<<edgeWeight[{i,Parent[i]}]<<" \n"; 


	return 0;
}