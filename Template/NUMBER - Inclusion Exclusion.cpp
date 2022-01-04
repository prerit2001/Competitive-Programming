/*https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/*/
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* SOl 1 : USING INCLUSION EXCLUSION PRINCIPLE */
void INCLUSION_EXCLUSION(){
	ll n; cin >> n;
	vector<string> s(n);
	vector<ll> store(n);
	unordered_map<char, ll> vowel;
	vowel['a'] = 1;
	vowel['e'] = 2;
	vowel['i'] = 4;
	vowel['o'] = 8;
	vowel['u'] = 16;
	for(ll i = 0; i < n; i ++){
		cin >> s[i];
		for(auto c: {'a', 'e', 'i', 'o', 'u'}){
			for(auto &jt: s[i]){
				if(jt == c){
					store[i] |= vowel[c];
				}
			}
		}
	}
	auto NC3 = [&](ll N) -> ll {
		ll var = 0;
		if(N >= 3) {
			var += N * (N - 1) * (N - 2);
			var /= 6;
		}
		return var;
	};
	ll ans = 0;
	for(ll mask = 1; mask < (1LL << 5); mask ++){
		ll setBit = 0;
		for(ll j = 0; j < 5; j ++){
			if(1 & (mask >> j)){
				setBit ++;
			}
		}
		ll cnt = 0;
		for(ll i = 0; i < n; i ++){
			bool flag = 1;
			for(ll j = 0; j < 5; j ++){
				if(1 & (mask >> j)){
					if(!(1 & (store[i] >> j))){
						flag = 0;
						break;
					}
				}
			}
			cnt += flag;
		}
		if(setBit % 2 == 1){
			ans += NC3(cnt); // inclusion
		}
		else{
			ans -= NC3(cnt); // exclusion
		}
	}
	cout << ans << '\n';
}


/* SOl 2 : USING DP WITH BITMASKING */
ll dp[10005][35][4];

ll go(ll curr, ll n, ll mask, ll cnt, vector<ll>& V){
	if(cnt < 0){
		return 0LL;
	}
	if(curr == n){
		return cnt == 0;
	}
	if(dp[curr][mask][cnt] != -1){
		return dp[curr][mask][cnt];
	}
	ll ans = go(curr + 1, n, mask, cnt, V);
	ll AllVowel = V[curr];
	if(AllVowel){
		if(cnt == 3){
			ans += go(curr + 1, n, AllVowel, cnt - 1, V);
		}
		else if(AllVowel & mask){
			ans += go(curr + 1, n, AllVowel & mask, cnt - 1, V);
		}
	}
	return dp[curr][mask][cnt] = ans;
}

void DP_WITH_BITMASKING() {
	ll n; cin >> n;
	vector<string> s(n);
	for(auto &it: s) {
		cin >> it;
	}
	unordered_map<char, ll> vowel;
	vowel['a'] = 1;
	vowel['e'] = 2;
	vowel['i'] = 4;
	vowel['o'] = 8;
	vowel['u'] = 16;
	memset(dp, -1, sizeof dp);
	vector<ll> V(n);
	for(ll curr = 0; curr < n; curr ++){
		ll AllVowel = 0;
		for(ll i = 0; i < s[curr].size(); i ++){
			if(vowel.count(s[curr][i])){
				AllVowel |= (vowel[s[curr][i]]);
			}
		}
		V[curr] = AllVowel;
	}
	ll ans = go(0, n, 0, 3, V);
	cout << ans << '\n';
}