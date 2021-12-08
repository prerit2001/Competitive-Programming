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

// range Sum
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
        St[Si] = (St[2 * Si] + St[2 * Si + 1]);
    }
    ll query(ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
        if (Qs > Se or Qe < Ss) return 0;
        if (Qs <= Ss and Qe >= Se) return St[Si];
        ll mid = (Ss + Se) >> 1;
        ll lSubTree = query(2 * Si, Ss, mid, Qs, Qe);
        ll rSubTree = query(2 * Si + 1, mid + 1, Se, Qs, Qe);
        return (lSubTree + rSubTree);
    }
    void update(ll Si, ll Ss, ll Se, ll q, ll val) {
        a[q] = val;
        if (Ss == Se) {
            St[Si] = a[Ss];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        if (Ss <= q and q <= mid)
            update(2 * Si, Ss, mid, q, val);
        else
            update(2 * Si + 1, mid + 1, Se, q, val);
        St[Si] = (St[2 * Si] + St[2 * Si + 1]);
    }
};

class segTree2D {
   public:
    vector<vector<ll>> seg2D;
    vector<vector<ll>> a;
    ll n, m;
    segTree2D(ll n, ll m, vector<vector<ll>> a) {
        this->n = n;
        this->m = m;
        seg2D.resize(5 * n, vector<ll>(5 * m, 0));
        this->a.resize(n + 1);
        for (ll i = 0; i < n; i++) {
            this->a[i + 1] = a[i];
        }
        Build2DSegTree(1, 1, n, n, m);
    }
    // SzeX4 = 4 * ColSize
    void Build2DSegTree(ll Si, ll Ss, ll Se, ll ColSize, ll RowSize) {
        if (Ss == Se) {
            segTree seg(ColSize, a[Ss]);
            for (ll i = 0; i < 5 * ColSize; i++) {
                seg2D[Si][i] = seg.St[i];
            }
            return;
        }
        ll mid = (Ss + Se) >> 1;
        Build2DSegTree(2 * Si, Ss, mid, ColSize, RowSize);
        Build2DSegTree(2 * Si + 1, mid + 1, Se, ColSize, RowSize);
        for (ll i = 0; i < 5 * ColSize; i++) {
            seg2D[Si][i] = seg2D[2 * Si][i] + seg2D[2 * Si + 1][i];
        }
    }
    ll queryColSum(vector<ll>& St, ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
        if (Qs > Se or Qe < Ss) return 0;
        if (Qs <= Ss and Qe >= Se) return St[Si];
        ll mid = (Ss + Se) >> 1;
        ll lSubTree = queryColSum(St, 2 * Si, Ss, mid, Qs, Qe);
        ll rSubTree = queryColSum(St, 2 * Si + 1, mid + 1, Se, Qs, Qe);
        return (lSubTree + rSubTree);
    }

    ll Query2dSegTree(ll Si, ll Ss, ll Se, ll Rs, ll Cs, ll Re, ll Ce,
                      ll RowSize, ll ColSize) {
        if (Rs > Se or Re < Ss) return 0;
        if (Rs <= Ss and Re >= Se)
            return queryColSum(seg2D[Si], 1, 1, ColSize, Cs, Ce);
        ll mid = (Ss + Se) >> 1;
        ll lSubTree =
            Query2dSegTree(2 * Si, Ss, mid, Rs, Cs, Re, Ce, RowSize, ColSize);
        ll rSubTree = Query2dSegTree(2 * Si + 1, mid + 1, Se, Rs, Cs, Re, Ce,
                                     RowSize, ColSize);
        return (lSubTree + rSubTree);
    }
    void updateColSum(ll Sx, ll Sy, ll Ss, ll Se, ll C, bool tight, ll val) {
        if (Ss == Se) {
            if (tight)
                seg2D[Sx][Sy] = val;
            else
                seg2D[Sx][Sy] = seg2D[2 * Sx][Sy] + seg2D[2 * Sx + 1][Sy];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        if (Ss <= C and C <= mid)
            updateColSum(Sx, 2 * Sy, Ss, mid, C, tight, val);
        else
            updateColSum(Sx, 2 * Sy + 1, mid + 1, Se, C, tight, val);
        seg2D[Sx][Sy] = (seg2D[Sx][2 * Sy] + seg2D[Sx][2 * Sy + 1]);
    }

    void Update2dSegTree(ll Si, ll Ss, ll Se, ll R, ll C, ll ColSize, ll val) {
        if (Ss == Se) {
            updateColSum(Si, 1, 1, ColSize, C, true, val);
            return;
        }
        ll mid = (Ss + Se) >> 1;
        if (Ss <= R and R <= mid)
            Update2dSegTree(2 * Si, Ss, mid, R, C, ColSize, val);
        else
            Update2dSegTree(2 * Si + 1, mid + 1, Se, R, C, ColSize, val);
        updateColSum(Si, 1, 1, ColSize, C, false, val);
    }
    ll query(ll x1, ll y1, ll x2, ll y2) {
        return Query2dSegTree(1, 1, n, x1, y1, x2, y2, n, m);
    }
    void update(ll x, ll y, ll val) {
        a[x][y] = val;
        Update2dSegTree(1, 1, n, x, y, m, val);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    ll m = n;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++) {
            if (s[j] != '.') a[i][j] = 1;
        }
    }
    segTree2D seg(n, m, a);
    while (q--) {
        ll t;
        cin >> t;
        switch (t) {
            case 2:
                ll x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << seg.query(x1, y1, x2, y2) << '\n';
                break;
            case 1:
                ll x, y;
                cin >> x >> y;
                a[x - 1][y - 1] ^= 1;
                seg.update(x, y, a[x - 1][y - 1]);
                break;
        }
    }
}

// forest queries 2