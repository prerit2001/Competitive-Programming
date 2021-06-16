// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

#include<bits/stdc++.h>
using namespace std;

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
        if(a > b){
        	parent[a] = parent[b]; 
        	return a;
        }
        else{
        	parent[b] = parent[a];
        	return b;
        }
    }
};


string answer(string a, string b, string s){
	string ans;
	DSU dsu(26);
	for(int i = 0 ; i < a.size() ; i ++){
		int k = dsu.union_set(a[i]-'a',b[i]-'a');
	}
	for(char c : s){
		ans.push_back((dsu.find_set(c-'a')+'a'));
	}
	return ans;
}

int main(){
	string a,b,s; cin >> a >> b >> s;
	cout << answer(a,b,s);
}