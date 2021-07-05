// https://atcoder.jp/contests/abc208/tasks/abc208_e

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int k;
string s;
bool minor = 0;

string int_to_str(int temp){
    
    deque<char> d;
    while(temp){
        d.push_front(char((temp%10)+'0'));
        temp/=10;
    }

    string ans; 
    for(char c : d){
        ans += c;
    }

    if(ans.size() == 0) return "0";

    return ans;
}

map<int,int> dp1[20][2];

int go1(int curr, int n, int prod = 1, int tight = 1){
	
	if(curr == n){
		return 1;
	}

	if(dp1[curr][tight].count(prod)) return dp1[curr][tight][prod];

	int ans = 0;
	int upper_bound = 9;

	if(tight == 1 and minor == 0){
		upper_bound = s[curr] - '0';
	}
	
	for(int i=1;i<=upper_bound;i++){
		if(i*prod <= k)
			ans += go1(curr+1,n,prod*i,(tight&(i==upper_bound)));
	}

	return dp1[curr][tight][prod] = ans;
}

int dp2[20][2][2];

int go2(int curr, int n, int ok = 0, int tight = 1){

	if(curr == n){
		if(ok)return 1;
		return 0;
	}

	if(dp2[curr][ok][tight] != -1) return dp2[curr][ok][tight];

	int ans = 0;
	int upper_bound = 9;

	if(tight == 1 and minor == 0){
		upper_bound = s[curr] - '0';
	}
	
	for(int i = 0;i<=upper_bound;i++){
		if(curr == 0 and i == 0){
			continue;
		}
		ans += go2(curr+1,n,ok|(i==0),(tight&(i==upper_bound)));
	}

	return dp2[curr][ok][tight] = ans;
}

void solve(){
	
	int n; cin >> n >> k;
	s = int_to_str(n);
	
	minor = 0;
	for(int i = 0; i < 20; i ++){
		for(int j = 0; j < 2; j ++){
			dp1[i][j].clear();
		}
	}
	int ans_without_zero = go1(0,s.size());
	minor = 1;
	for(int i = 1; i < s.size(); i ++){
		for(int i = 0; i < 20; i ++){
		for(int j = 0; j < 2; j ++){
			dp1[i][j].clear();
		}
	}
		ans_without_zero += go1(0,i);
	}

	minor = 0;
	memset(dp2, -1, sizeof dp2);
	int ans_with_zero = go2(0,s.size());
	minor = 1;
	for(int i = 1; i < s.size(); i ++){
		memset(dp2, -1, sizeof dp2);
		ans_with_zero += go2(0,i);
	}

	cout << ans_with_zero + ans_without_zero << '\n';
}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	
}