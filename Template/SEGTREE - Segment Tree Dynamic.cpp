// https://cses.fi/problemset/task/1144/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
typedef long long ll;

struct Node {
    ll value;
    struct Node *L, *R;
};

struct Node* getnode() {
    struct Node* temp = new struct Node;
    temp->value = 0;
    temp->L = NULL;
    temp->R = NULL;
    return temp;
}

struct Node* root;

void UpdateHelper(struct Node* curr, ll index, ll L, ll R, ll delta) {
    if (L > index || R < index) return;

    if (L == R && L == index) {
        curr->value += delta;
        return;
    }

    ll mid = L - (L - R) / 2;
    ll sum1 = 0, sum2 = 0;

    if (index <= mid) {
        if (curr->L == NULL) {
            curr->L = getnode();
        }

        UpdateHelper(curr->L, index, L, mid, delta);
    } else {
        if (curr->R == NULL) {
            curr->R = getnode();
        }

        UpdateHelper(curr->R, index, mid + 1, R, delta);
    }

    if (curr->L) sum1 = curr->L->value;

    if (curr->R) sum2 = curr->R->value;

    curr->value = sum1 + sum2;
    return;
}

ll queryHelper(struct Node* curr, ll a, ll b, ll L, ll R) {
    if (curr == NULL) return 0;

    if (L > b || R < a) return 0;

    if (L >= a && R <= b) return curr->value;

    ll mid = L - (L - R) / 2;

    return queryHelper(curr->L, a, b, L, mid) + queryHelper(curr->R, a, b, mid + 1, R);
}

ll query(ll L, ll R) { return queryHelper(root, L, R, 1, 1e9); }

void update(ll index, ll value) { UpdateHelper(root, index, 1, 1e9, value); }

void solve(ll tc) {
    ll n, m;
    cin >> n >> m;

    root = getnode();

    vector<ll> arr(n);

    vector<ll> salaries(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        update(arr[i], 1);
        salaries[i] = arr[i];
    }

    while (m--) {
        char ch;
        cin >> ch;

        if (ch == '?') {
            ll a, b;
            cin >> a >> b;
            cout << query(a, b) << endl;
        } else {
            ll pos, salary;
            cin >> pos >> salary;
            update(salaries[pos], -1);
            update(salary, 1);
            salaries[pos] = salary;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tt = 1;
    for (ll i = 1; i <= tt; i++) {
        solve(i);
    }

    return 0;
}