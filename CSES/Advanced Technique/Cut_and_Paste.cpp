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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r) {
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

typedef struct node {
    int val, prior, size;
    struct node *l, *r;
} node;

typedef node *pnode;

int sz(pnode t) { return t ? t->size : 0; }

void upd_sz(pnode t) {
    if (t) {
        t->size = sz(t->l) + 1 + sz(t->r);
    }
}

pnode find(pnode t, int key) {
    if (t == NULL || t->val == key) {
        return t;
    }

    return find(t->val < key ? t->r : t->l, key);
}

void split(pnode t, pnode &l, pnode &r, int key) {
    if (!t) {
        l = r = NULL;
    } else if (t->val <= key) {
        split(t->r, t->r, r, key);
        l = t;
    } else {
        split(t->l, l, t->l, key);
        r = t;
    }

    upd_sz(t);
}

void merge(pnode &t, pnode l, pnode r) {
    if (!l || !r) {
        t = l ? l : r;
    } else if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }

    upd_sz(t);
}

void insert(pnode &t, pnode it) {
    if (!t) {
        t = it;
    } else if (it->prior > t->prior) {
        split(t, it->l, it->r, it->val);
        t = it;
    } else {
        insert(t->val <= it->val ? t->r : t->l, it);
    }

    upd_sz(t);
}

void erase(pnode &t, int key) {
    pnode p = find(t, key);
    if (p == NULL) {
        return;
    }

    pnode temp = t;
    merge(t, p->l, p->r);
    free(temp);

    upd_sz(t);
}

pnode init(int val) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val = val;
    ret->size = 1;
    ret->prior = rand();
    ret->l = ret->r = NULL;
    return ret;
}

int order_of_key(pnode &t, int val)  // 1 indexed
{
    pnode l, r, mid;
    split(t, l, r, val - 1);
    split(r, mid, r, val);
    int ans = -1;
    if (sz(mid) == 1) ans = 1 + sz(l);
    merge(r, mid, r);
    merge(t, l, r);
    return ans;
}

class Treap {
   public:
    struct data {
        int priority, val, cnt;
        data *l, *r;

        data() { val = 0, cnt = 0, l = NULL, r = NULL; }

        data(int _val) {
            val = _val, cnt = 1;
            l = NULL, r = NULL;
            priority = getRand(1, 2e9);
        }
    };

    typedef struct data *node;

    node head;

    Treap() : head(0) {}

    int cnt(node cur) { return cur ? cur->cnt : 0; }

    void updateCnt(node cur) {
        if (cur) cur->cnt = cnt(cur->l) + cnt(cur->r) + 1;
    }

    void push(node cur)  // Lazy Propagation
    {
        ;
    }

    void combine(node &cur, node l, node r) {
        if (!l) {
            cur = r;
            return;
        }
        if (!r) {
            cur = l;
            return;
        }
        // Merge Operations like in segment tree
    }

    void reset(node &cur)  // To reset other fields of cur except value and cnt
    {
        if (!cur) return;
    }

    void operation(node &cur) {
        if (!cur) return;
        reset(cur);
        combine(cur, cur->l, cur);
        combine(cur, cur, cur->r);
    }

    void splitPos(node cur, node &l, node &r, int k, int add = 0) {
        if (!cur) return void(l = r = 0);
        push(cur);
        int idx = add + cnt(cur->l);
        if (idx <= k)
            splitPos(cur->r, cur->r, r, k, idx + 1), l = cur;
        else
            splitPos(cur->l, l, cur->l, k, add), r = cur;
        updateCnt(cur);
        operation(cur);
    }

    void split(node cur, node &l, node &r, int k) {
        if (!cur) return void(l = r = 0);
        push(cur);
        int idx = cur->val;
        if (idx <= k)
            split(cur->r, cur->r, r, k), l = cur;
        else
            split(cur->l, l, cur->l, k), r = cur;
        updateCnt(cur);
        operation(cur);
    }

    void merge(node &cur, node l, node r) {
        push(l);
        push(r);
        if (!l || !r)
            cur = l ? l : r;
        else if (l->priority > r->priority)
            merge(l->r, l->r, r), cur = l;
        else
            merge(r->l, l, r->l), cur = r;
        updateCnt(cur);
        operation(cur);
    }

    void insert(int val) {
        if (!head) {
            head = new data(val);
            return;
        }
        node l, r, mid, mid2, rr;
        mid = new data(val);
        split(head, l, r, val - 1);
        merge(l, l, mid);
        split(r, mid2, rr, val);
        merge(head, l, rr);
    }

    void erase(int val) {
        node l, r, mid;
        split(head, l, r, val - 1);
        split(r, mid, r, val);
        merge(head, l, r);
    }

    void inorder(node cur) {
        if (!cur) return;
        push(cur);
        inorder(cur->l);
        cout << cur->val << " ";
        inorder(cur->r);
    }

    void inorder() {
        inorder(head);
        cout << endl;
    }

    void clear(node cur) {
        if (!cur) return;
        clear(cur->l), clear(cur->r);
        delete cur;
    }

    void clear() { clear(head); }

    int find_by_order(int x)  // 1 indexed
    {
        if (!x) return -1;
        x--;
        node l, r, mid;
        splitPos(head, l, r, x - 1);
        splitPos(r, mid, r, 0);
        int ans = -1;
        if (cnt(mid) == 1) ans = mid->val;
        merge(r, mid, r);
        merge(head, l, r);
        return ans;
    }

    int order_of_key(int val)  // 1 indexed
    {
        node l, r, mid;
        split(head, l, r, val - 1);
        split(r, mid, r, val);
        int ans = -1;
        if (cnt(mid) == 1) ans = 1 + cnt(l);
        merge(r, mid, r);
        merge(head, l, r);
        return ans;
    }
};

void solve() {
    // Treap t;
    pnode t;
    while (true) {
        ll i, x;
        cin >> i;
        if (i == -1) break;
        cin >> x;
        if (i == 1) {
            insert(t, init(x));
        }
        if (i == 2) {
            erase(t, x);
        }
        if (i == 3) {
            cout << "-";
            // cout << order_of_key(t, x);
            cout << '\n';
        }
        // if (i == 4) {
        //     cout << t.find_by_order(x);
        //     cout << '\n';
        // }
    }
}