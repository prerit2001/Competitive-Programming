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
        return a;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    int temp = dsu.union_set(i,j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dsu.find_set(i) == i) ans ++;
        }
        return ans;
    }
};