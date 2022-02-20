#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); } // cin >> pair<T1, T2>
template<typename T> istream& operator>>(istream &istream, vector<T> &v){ for (auto &it : v) cin >> it; return istream; } // cin >> vector<T>
template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }  // cout << pair<T1, T2>
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; } // cout << vector<T>
template <typename T> void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args> void print(T &&t, Args &&... args){ cout << t << " "; print(forward<Args>(args)...); }
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = 2e18;
ll power(ll x, ll y, ll mod) { ll res = 1; x = x % mod; if (x == 0) return 0; while (y > 0) { if (y & 1) res = (res * x) % mod; y = y >> 1; x = (x * x) % mod; } return res; }
void google(){static int _ = 1; cout << "Case #" << _ ++ << ": ";}
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--) { 
        solve();
    }
    return 0;
}

void solve() {

}