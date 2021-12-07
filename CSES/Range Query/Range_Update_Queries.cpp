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
signed main() {
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#define int int64_t

int a[200001] = {};
int ST[800001] = {};
int lazyDiary[800001] = {};

// Range sum Query with Range Updates
class RUQSQ {
   public:
    void buildTree(int Si, int Ss, int Se) {
        if (Ss == Se) {
            ST[Si] = a[Ss];
            return;
        }
        int mid = (Ss + Se) / 2;
        buildTree(2 * Si, Ss, mid);
        buildTree(2 * Si + 1, mid + 1, Se);
        ST[Si] = ST[2 * Si] + ST[2 * Si + 1];
    }
    int answeringQueries(int Si, int Ss, int Se, int Qs, int Qe) {
        // Firstly checking pending updates on the node we gonna proceed
        if (lazyDiary[Si] != 0) {
            if (Ss != Se) {
                lazyDiary[2 * Si] += lazyDiary[Si];
                lazyDiary[2 * Si + 1] += lazyDiary[Si];
            }
            ST[Si] += lazyDiary[Si] * (Se - Ss + 1);
            lazyDiary[Si] = 0;
        }

        if (Qe < Ss or Se < Qs) return 0;
        if (Qs <= Ss and Se <= Qe) return ST[Si];
        int mid = (Ss + Se) / 2;
        return answeringQueries(2 * Si, Ss, mid, Qs, Qe) +
               answeringQueries(2 * Si + 1, mid + 1, Se, Qs, Qe);
    }
    void updateRange(int Si, int Ss, int Se, int Qs, int Qe, int val) {
        // Firstly checking pending updates on the node we gonna proceed
        if (lazyDiary[Si] != 0) {
            if (Ss != Se) {
                lazyDiary[2 * Si] += lazyDiary[Si];
                lazyDiary[2 * Si + 1] += lazyDiary[Si];
            }
            ST[Si] += lazyDiary[Si] * (Se - Ss + 1);
            lazyDiary[Si] = 0;
        }

        if (Qe < Ss or Se < Qs) return;
        if (Qs <= Ss and Se <= Qe) {
            if (Ss != Se) {
                lazyDiary[2 * Si] += val;
                lazyDiary[2 * Si + 1] += val;
            }
            ST[Si] += val * (Se - Ss + 1);
            return;
        }
        int mid = (Ss + Se) / 2;
        updateRange(2 * Si, Ss, mid, Qs, Qe, val);
        updateRange(2 * Si + 1, mid + 1, Se, Qs, Qe, val);
        ST[Si] = ST[2 * Si] + ST[2 * Si + 1];
    }
};

void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    int i = 0;
    for (i = 1; i <= n; i++) cin >> a[i];
    // BUILD TREE
    RUQSQ tree;
    tree.buildTree(1, 1, n);

    while (q--) {
        int Q;
        cin >> Q;

        // UPDATE
        if (Q == 2) {
            int l, r;
            cin >> l;
            cout << tree.answeringQueries(1, 1, n, l, l) << endl;
        }

        // RANGE SUM
        if (Q == 1) {
            int l, r;
            cin >> l >> r;
            int val;
            cin >> val;
            tree.updateRange(1, 1, n, l, r, val);
        }
    }
}