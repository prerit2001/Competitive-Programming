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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    ll value;
    ll sz;
    ll prior;
    ll sum;
    node *l;
    node *r;
    bool rev;
    node(ll value){
        this -> value = value;
        this -> sz = 1;
        this -> prior = rng();
        this -> sum = value;
        this -> rev = 0;
        this -> l = nullptr;
        this -> r = nullptr;
    }
};

ll sz(node *x){
    return x ? x -> sz : 0ll;
}

ll sum(node *x){
    return x ? x -> sum : 0ll;
}

void recalc(node *x){
    assert(x);
    x -> sz = 1 + sz(x -> l) + sz(x -> r);
    x -> sum = x -> value + sum(x -> l) + sum(x -> r);
}

void push(node* x) {
  if (!x) return;
  if (x->rev) {
    swap(x->l, x->r);
    if (x->l) x->l->rev ^= true;
    if (x->r) x->r->rev ^= true;
    x->rev = false;
  }
}

node* merge(node* l, node* r) {
    push(l);
    push(r);
    if (!l) return r;
    if (!r) return l;
    if (l->prior < r->prior) {
        l->r = merge(l->r, r);
        recalc(l);
        push(l);
        return l;
    }
    else{
        r->l = merge(l, r->l);
        recalc(r);
        push(r);
        return r;
    }
}

pair<node*, node*> split(node* x, ll k){
    push(x);
    if (!x) {
        return {nullptr, nullptr};
    }
    if (k <= sz(x->l)) {
        pair<node*, node*> p = split(x->l, k);
        node* l = p.first;
        node* r = p.second;
        x->l = r;
        recalc(x);
        push(x);
        return make_pair(l, x);
    }
    else{
        pair<node*, node*> p = split(x->r, k - sz(x->l) - 1);
        node* l = p.first;
        node* r = p.second;
        x->r = l;
        recalc(x);
        push(x);
        return make_pair(x, r);
    }
}

void solve() {
    ll n; cin >> n;
    ll q; cin >> q;
    vector<ll> v(n);
    for(auto &it : v) cin >> it;
    node* root = nullptr;
    for(auto &it : v) root = merge(root, new node(it));
    while(q --){
        ll type, l, r; cin >> type >> l >> r;
        if(type == 1){ // reverse subarray
            pair<node*, node*> p1 = split(root, l - 1);
            pair<node*, node*> p2 = split(p1.second, r - l + 1);
            p2.first -> rev ^= 1;
            root = merge(p1.first, p2.first);
            root = merge(root, p2.second);
        }
        else { // sum subarray
            pair<node*, node*> p1 = split(root, l - 1);
            pair<node*, node*> p2 = split(p1.second, r - l + 1);
            cout << sum(p2.first) << '\n';
            root = merge(p1.first, p2.first);
            root = merge(root, p2.second);
        }
    }
}