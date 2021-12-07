#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
ll power(ll x, ll y, ll mod) {
    ll res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
void solve();
int main() {
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<ll> a(n);
    ll ans = m;
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll v = 0;
        reverse(s.begin(), s.end());
        for (ll i = 0; i < m; i++) {
            v += (s[i] - '0') * (1LL << i);
        }
        for (ll j = 0; j < i; j++) {
            ans = min(ans, (ll)__builtin_popcount(v ^ a[j]));
        }
        a[i] = v;
    }
    cout << ans;
}

/*

TLE

struct Node {
    Node* next[2];
    Node() {
        for (ll i = 0; i < 2; i++) {
            next[i] = nullptr;
        }
    }
};

map<Node*, ll> dp[31];

class Trie {
   public:
    void insert(int n, string s, Node* head) {
        Node* temp = head;
        for (ll i = 0; i < n; i++) {
            int bit = s[i] - '0';
            if (temp->next[bit] == nullptr) {
                temp->next[bit] = new Node();
            }
            temp = temp->next[bit];
        }
    }
    ll HammingDistance(int n, string s, Node* head, int curr) {
        if (curr == n) return 0;
        if (dp[curr].count(head)) return dp[curr][head];
        ll bit = s[curr] - '0';
        ll ans = n;
        if (head->next[bit] != nullptr) {
            ans = min(ans, HammingDistance(n, s, head->next[bit], curr + 1));
        }
        if (head->next[1 ^ bit] != nullptr) {
            ans = min(ans,
                      1 + HammingDistance(n, s, head->next[1 ^ bit], curr + 1));
        }
        return dp[curr][head] = ans;
    }
};

void solve() {
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<string> a(n);
    Trie trie;
    Node* head = new Node();
    ll ans = m;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        Node* temp = head;
        for (ll j = 0; j < 31; j++) {
            dp[j].clear();
        }
        ans = min(ans, trie.HammingDistance(m, a[i], temp, 0));
        trie.insert(m, a[i], head);
    }
    cout << ans;
}

*/
