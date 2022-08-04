           /********************************************************************          
      * *                 AUTHOR-- PRERIT KUMAR JHA                         *
      * * !!!!!!!! IMPOSSIBLE MEANS YOU HAVEN'T FOUND SOLUTION YET !!!!!!!  *
      *********************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define                       ll                                 long long int
#define                      test                       int t;cin>>t;while(t--)
#define                  arrayscan(a,n)            for(ll i=0;i<n;cin>>a[i++]);
#define                      mod                                    1000000007
#define                      endl                                         "\n"
#define                       pb                                     push_back
#define                       mp                                     make_pair
#define                       pf                                    push_front
#define                      popb                                     pop_back
#define                      popf                                    pop_front
#define                    forr(i,a,b)                      for(ll i=a;i<b;++i)
#define                   rforr(i,a,b)                   for(ll i=b-1;i>=a;i--)             
#define   fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

 

int main(){
    //*******************//ONLINE JUDGE//************************//
               //###############################//

                      #ifndef ONLINE_JUDGE
                freopen("input.txt", "r", stdin);
               freopen("output.txt", "w", stdout);
                            #endif

               //################################//             
    //*******************//FAST INPUT/OUTPUT//*******************//
                          //#############//

                               fastio;

                          //#############//     
    //*******************//START CODE HERE//*********************//
  test{ 
      
      
  
  }

  return 0;
}


/*          # ################################### #
            #     DSA (BASIC) -- (___RECALL___) - #
            * *********************************** *
            *   1. PRIORITY QUEUE                 *
            *   2. QUEUE                          *
            *   3. STACK                          *
            *   4. MAP                            *  
            *   5. SET                            *
            *   6. VECTOR<make_pair<int,int>>     * 
            *   7. DEQUE                          *
            *   8. MULTISET                       *
            *   9. REGEX                          *
            *  10. Reserve in map                 *
            ***************************************
*/
/*
	Time complexity O(E + VlogV):
	Space complexity O(V)
*/
/* 
	M1: Priority Queue 
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int LIMIT = 1e5 + 5;

vector<pair<int,int>> adj[LIMIT];
int dist[LIMIT];
int vis[LIMIT];

void dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	dist[0] = 0;
	Q.push({0,0});
	while(!Q.empty()){
		auto p = Q.top();
		Q.pop();
		if(vis[p.second]){
			continue;
		}
		vis[p.second] = 1;
		for(auto &i : adj[p.second]){
			if(!vis[i.first] and dist[i.first] > dist[p.second] + i.second){
				dist[i.first] = dist[p.second] + i.second;
				Q.push({dist[i.first],i.first});
			}
		}
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n, m; cin >> n >> m;
		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
		}
		memset(vis,0,sizeof(vis));
		for(i=1;i<n;i++){
			dist[i] = 1e15;
		}
		dijkstra();
		for(i=0;i<n;i++){
			cout << dist[i] << " ";
		}
		cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
/*
	M2: Set
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int LIMIT = 1e5 + 5;

vector<pair<int,int>> adj[LIMIT];
int dist[LIMIT];
int vis[LIMIT];

void dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	dist[0] = 0;
	Q.push({0,0});
	while(!Q.empty()){
		auto p = Q.top();
		Q.pop();
		if(vis[p.second]){
			continue;
		}
		vis[p.second] = 1;
		for(auto &i : adj[p.second]){
			if(!vis[i.first] and dist[i.first] > dist[p.second] + i.second){
				dist[i.first] = dist[p.second] + i.second;
				Q.push({dist[i.first],i.first});
			}
		}
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n, m; cin >> n >> m;
		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
		}
		memset(vis,0,sizeof(vis));
		for(i=1;i<n;i++){
			dist[i] = 1e15;
		}
		dijkstra();
		for(i=0;i<n;i++){
			cout << dist[i] << " ";
		}
		cout << '\n';
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
