#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve();
int main() {
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

const int N = 1e5 + 5;
vector<ll> adj[N];  // adjecency list
ll dp[N];           // will store subtree gcd
vector<ll> a(N);    // value associated with each node
ll ans = 0;
vector<ll> euler;   // vector to store eular tour of array
pair<ll, ll> p[N];  // array of pairs to store start and end index of node in
                    // eular vector

void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        adj[i].clear();
        dp[i] = 0;
        a[i] = 0;
    }
    ans = 0;
    euler.clear();
}

void dfs(ll curr, ll prev) {
    dp[curr] = a[curr];
    euler.push_back(curr);
    p[curr].first = euler.size() - 1;
    for (auto next : adj[curr]) {
        if (next != prev) {
            dfs(next, curr);
            dp[curr] = __gcd(dp[curr], dp[next]);
        }
    }
    euler.push_back(curr);
    p[curr].second = euler.size() - 1;
}

class segTree {
   public:
    ll n;           // size of array
    vector<ll> a;   // 1-index array
    vector<ll> St;  // segTree Storage
    segTree(ll n, vector<ll> a) {
        this->n = n;
        this->a.resize(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            this->a[i + 1] = a[i];
        }
        St.resize(5 * n);
        build(1, 1, n);
    }
    void build(ll Si, ll Ss, ll Se) {
        if (Ss == Se) {
            St[Si] = a[Ss];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        build(2 * Si, Ss, mid);
        build(2 * Si + 1, mid + 1, Se);
        St[Si] = __gcd(St[2 * Si], St[2 * Si + 1]);
    }
    ll query(ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
        if (Qs > Qe) return 0;
        if (Qs > Se or Qe < Ss) return 0;
        if (Qs <= Ss and Qe >= Se) return St[Si];
        ll mid = (Ss + Se) >> 1;
        ll lSubTree = query(2 * Si, Ss, mid, Qs, Qe);
        ll rSubTree = query(2 * Si + 1, mid + 1, Se, Qs, Qe);
        if (lSubTree == 0) return rSubTree;
        if (rSubTree == 0) return lSubTree;
        return __gcd(lSubTree, rSubTree);
    }
};

void dfs2(ll curr, ll prev, segTree& seg) {
    ll val = 0;
    for (auto next : adj[curr]) {
        if (next != prev) {
            dfs2(next, curr, seg);
            val += dp[next];
        }
    }
    ll pre = seg.query(1, 1, euler.size(), 1, p[curr].first);
    ll suf = seg.query(1, 1, euler.size(), p[curr].second + 2, euler.size());
    val += __gcd(pre, suf);
    ans = max(ans, val);
}

void solve() {
    ll n;
    cin >> n;
    init(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++) cin >> a[i];
    ll gcd = 0;
    dfs(1, 0);
    vector<ll> b;
    for (auto it : euler) {
        b.push_back(a[it]);
    }
    segTree seg(b.size(), b);
    dfs2(1, 0, seg);
    cout << ans << '\n';
}
