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