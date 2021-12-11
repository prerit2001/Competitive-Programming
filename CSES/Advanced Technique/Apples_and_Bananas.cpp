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

typedef double ld;
typedef complex<ld> cd;
const int SIZE = 1 << 19;
const ld PI = acos(-1);

void fft(vector<cd> &a, bool inv) {
    int N = (int)a.size();
    for (int i = 1, j = 0; i < N; i++) {
        int bit = N >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= N; len <<= 1) {
        ld theta = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(theta), sin(theta));
        for (int i = 0; i < N; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv)
        for (cd &z : a) z /= N;
}

vector<ll> multiply(vector<ll> a, vector<ll> b, ll n = (1LL << 20)) {
    vector<cd> fa(n), fb(n);
    for (auto &it : a) fa[it] += 1;
    for (auto &it : b) fb[it] += 1;
    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
        ans[i] = llround(fa[i].real());
    }
    return ans;
}

void solve() {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<ll> ans = multiply(a, b);
    for (ll i = 2; i <= 2 * k; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}