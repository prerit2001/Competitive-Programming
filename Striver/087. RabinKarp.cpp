/*
	Below Implemented Class is Only Valid for String Hashing
	Necessary Precautions :
		hash(a, p, mod) = a0 + a1 * p^1 + a2 * p^2 + a3 * p^3 ..... aN * p^N
		condition :
			max(ai) < p < mod
			gcd(p, mod) = 1 
			mod = use prime most likely
	// Trick to avoid collision
		-> genrate two different hash value using two diffent MOD value 
		-> let h1 and h2 be the differnt hash value genrated
		-> combine h1 and h2 to get a unique h
		-> eg -> h = h1 * 100000 + h2
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll power(ll x,ll y, ll p){
    ll res = 1;  
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

ll ModInv(ll a,ll mod){
	return power(a,mod-2,mod)%mod;
};

// Rolling Hash
class RollingHash{
public:
	vector<ll> A;
	ll n;
	vector<ll> hash;
	ll MOD;
	ll P;
	vector<ll> powTable;
    vector<ll> inv;
	RollingHash(string& s, ll mod = 1e9 + 7){
		this -> n = s.size();
		this -> hash.resize(this -> n, 0);
		this -> powTable.resize(this -> n, 0);
        this -> inv.resize(this -> n, 0);
		for(auto &c : s){
			this -> A.push_back(c - 'a'); // CHECKPOINT 1 : if binary string -> (c - '0')
		}
		P = 40; // CHECKPOINT 2 : change this accourding to the condition -> max(ai) < p < mod
        MOD = mod;
		build();
	}
	void build(){
		ll pre = 0;
		ll power = 1;
		for(ll i = 0; i < n; i ++){
			pre = (pre + ((A[i]%MOD) * (power%MOD)) % MOD) % MOD;
			hash[i] = pre;
			powTable[i] = power;
            inv[i] = ModInv(powTable[i], MOD);
			power = ((power) * (P % MOD)) % MOD;
		}
	}
	ll getRangeHash(ll l, ll r){
		if(l < 0 or l >= n or l > r){
			assert(0);
			return -1;
		}
		if(l == 0){
			return hash[r];
		}
		else{
			ll numerator = (hash[r] - hash[l-1] + MOD) % MOD;
			ll denominator = l;
			return ((numerator % MOD) * inv[denominator]) % MOD;
		}
	}
};


int main(){
	string s = "prerit";
	ll n = s.size();
	RollingHash hash(s);


	cout << hash.getRangeHash(0, n-1); // 0 index
}