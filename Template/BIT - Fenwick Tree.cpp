// Quick hack : (i & (-i)) results in last set bit

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

class FenwickTree {
   public:
    int n;
    vector<int> BIT;
    FenwickTree(int n) {
        this->n = n + 1;
        BIT.resize(n + 2, 0);
    }
    // initially all values of BIT are 0, so update all the delta's first
    void update(int idx, int delta) {
        while (idx <= n) {
            BIT[idx] += delta;
            idx += (idx & (-idx));
            // eg: let idx = 13 and n = 16, then idx goes like
            // -> 01101 (13) -> 01110 (14) -> 10000 (16)
        }
    }
    // compute sum from [1:l]
    int pre_sum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= (idx & (-idx));
            // eg: let idx = 13 and n = 16, then idx goes like ->
            // 01101 (13) -> 01100 (12) -> 01000 (8) -> 00000 (0)
        }
        return sum;
    }
    // compute sum from [l:r]
    int range_sum(int l, int r) { return pre_sum(r) - pre_sum(l - 1); }
};

void solve() {
    int n;
    cin >> n;
    FenwickTree fenTree(n);
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fenTree.update(i + 1, a[i] - 0);
        // since idx starts with 1, *** change value at idx to
        // val then add (val - a[idx]) to a[idx] ***
    }

    // query
    cout << fenTree.range_sum(2, 2) << '\n';  // idx is 1-based

    fenTree.update(2, 2 - a[2 - 1]);
    a[2 - 1] = 2;  // *** change value at idx to val then add (val - a[idx]) to
                   // a[idx] ***

    cout << fenTree.range_sum(1, 2) << '\n';  // idx is 1-based
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
}
