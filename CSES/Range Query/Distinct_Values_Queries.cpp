#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
const int rootN = 555;
 
int freq[200000];
int distinct;
int ar[200000];
 
struct query {
    int L;
    int R;
    int q_no;
    int block_no;
    bool operator<(query& q2) {
        if (block_no < q2.block_no)
            return 1;
        else if (block_no > q2.block_no)
            return 0;
        else
            return R < q2.R;
    }
};
 
void Add(int& elem) {
    if (!freq[elem]) distinct++;
    freq[elem]++;
}
void Remove(int& elem) {
    freq[elem]--;
    if (!freq[elem]) distinct--;
}
 
void adjust(int& curr_l, int& curr_r, query& q) {
    while (curr_l > q.L) {
        curr_l--;
        Add(ar[curr_l]);
    }
    while (curr_r < q.R) {
        curr_r++;
        Add(ar[curr_r]);
    }
    while (curr_l < q.L) {
        Remove(ar[curr_l]);
        curr_l++;
    }
    while (curr_r > q.R) {
        Remove(ar[curr_r]);
        curr_r--;
    }
}
 
void solve(vector<query>& queries) {
    vector<int> answer(queries.size());
    sort(queries.begin(), queries.end());
    memset(freq, 0, sizeof freq);
    distinct = 1;
 
    int curr_l = queries[0].L;
    int curr_r = queries[0].L;
 
    freq[ar[curr_l]]++;
 
    for (query& qr : queries) {
        adjust(curr_l, curr_r, qr);
        answer[qr.q_no] = distinct;
    }
 
    for (int x : answer) cout << x << '\n';
}
 
int main() {
    fast_io;
    int n, q;
    cin >> n >> q;
 
    map<int, int> coordinateCompress;
    int compressed_Num = 1;
 
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (coordinateCompress.find(ar[i]) != coordinateCompress.end()) {
            ar[i] = coordinateCompress[ar[i]];
        } else {
            coordinateCompress[ar[i]] = compressed_Num;
            ar[i] = compressed_Num++;
        }
    }
 
    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        queries[i].L = u - 1;
        queries[i].R = v - 1;
        queries[i].q_no = i;
        queries[i].block_no = u / rootN;
    }
    solve(queries);
    return 0;
}