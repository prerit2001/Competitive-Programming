#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = 2e18;
template<typename T1, typename T2>ostream& operator<<(ostream &ostream, const pair<T1,T2>&p){return (ostream << p.first << " " << p.second);} 
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; } template <typename T> void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args> void print(T &&t, Args &&... args){ cout << t << " "; print(forward<Args>(args)...); }
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(0); return 0; }();