// DSU
class Solution {
public:
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
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        DSU dsu(n);
        for(int i = 0; i < n; i ++){
            int temp = dsu.union_set(e[i][0]-1,e[i][1]-1);
            if(temp == -1) return e[i];
        }
        return e.back();
    }
};