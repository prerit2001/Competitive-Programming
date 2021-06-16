// https://codeforces.com/contest/1534/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

class DSU{
public:
    vector<int> parent, sz;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n);
        sz.resize(n);
        for ( int i = 0; i < n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
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
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = parent[a];
        sz[a] += sz[b];
        return sz[a];
    }
};

void solve(int i = 0, int j = 0){
	int n; cin >> n;
	int a[n];
	map<int,int> aa,bb;
	for(i=0;i<n;i++){
		cin >> a[i];
		aa[a[i]] = i;
	}
	int b[n];
	for(i=0;i<n;i++){
		cin >> b[i];
		bb[b[i]] = i;
	}
	DSU dsu(n);
	for(i=0;i<n;i++){
		int temp1 = dsu.union_set(a[i]-1,b[i]-1);
	}
	int cnt = 1;
	for(int i = 0;i < n;i ++){
		if(dsu.find_set(i) == i){
			cnt *= 2;
			cnt %= int(1e9+7);
		}
	}
	cout << cnt << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}