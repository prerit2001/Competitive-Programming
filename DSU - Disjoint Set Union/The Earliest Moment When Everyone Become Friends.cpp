https://www.codingninjas.com/codestudio/problems/the-earliest-moment-when-everyone-become-friends_1376604?leftPanelTab=0

#include<bits/stdc++.h>
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
    int union_set( int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a == b){
            return sz[a];
        }
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = parent[a];
        sz[a] += sz[b];
        return sz[a];
    }
};

int minTime(vector<vector<int>> &logs, int n){
		DSU dsu(n+1);
		sort(logs.begin(),logs.end());
		for(auto v : logs){
			int ans = dsu.union_set(v[1],v[2]);
			if(ans == n) return v[0];
		}
		return -1;
}