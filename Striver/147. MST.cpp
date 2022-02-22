/*
	Prims
	Time O(VlogV + (E logV + V) = O(E logV)
	Space O(V)
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int N,M;

const int LIMIT = 1e5+5;
vector<pair<int,int>> adj[LIMIT];
bool vis[LIMIT];

int ans = 0;

void prim_minimum_spanning_tree(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.push({0,0});
	while(!Q.empty()){
		auto u = Q.top();
		Q.pop();
		if(vis[u.second]){
			continue;
		}
		ans += u.first;
		vis[u.second] = 1;
		for(auto [v,w] : adj[u.second]){
			if(!vis[v]){
				Q.push({w,v});
			}
		}
	}
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	int i,j,t=1;
	// cin>>t;
	while(t--){
		int n,m; cin >> n >> m;
		N = n, M = m;

		for(i=0;i<m;i++){
			int u,v,w; cin >> u >> v >> w;
			adj[u-1].push_back({v-1,w});
			adj[v-1].push_back({u-1,w});
		}

		memset(vis,false,sizeof(vis));

		prim_minimum_spanning_tree();

		// check if any disconnected component
		for(i=0;i<n;i++){
			if(!vis[i]){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}

		cout << ans << '\n';
	}	
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
/*
	Kruskals
	O(ElogV)
*/
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

class DSU{
public:
    vector<int> parent, size;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n);
        size.resize(n);
        iota(parent.begin(),parent.end(),0);
        for (int i = 0; i < n; i ++){
            size[i] = 1;
        }
    }
    int group_size(int a){
        int parent = find_set(a);
        return size[parent];
    }
    int find_set(int a){
        if (parent[a] == a)
            return a;
        return parent[a] = find_set(parent[a]);
    }
    int union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a == b){
            return -1;
        }
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = parent[a];
        size[a] += size[b];
        return a;
    }
    void print_groups(){
        map<int,vector<int>> group;
        for(int i = 0; i < n; i ++){
            group[find_set(i)].push_back(i);
        }
        for(auto v : group){
            cout << v.first << " : [ ";
            for(auto ele : v.second){
                cout << ele << " "; 
            }
            cout << "]\n";
        }
    }
};

void solve() {
	ll n; cin >> n;
	ll m; cin >> m;
	vector<vector<ll>> edges;
	for(ll i = 0; i < m; i ++){
		ll u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	sort(all(edges), [&](vector<ll>& X, vector<ll>& Y){
		return X[2] < Y[2];
	});
	DSU dsu(n + 1);
	ll cost = 0;
	for(auto &edge: edges){
		if(dsu.find_set(edge[0]) != dsu.find_set(edge[1])){
			dsu.union_set(edge[0], edge[1]);
			cost += edge[2];
		}
	}
	cout << cost << '\n';
}