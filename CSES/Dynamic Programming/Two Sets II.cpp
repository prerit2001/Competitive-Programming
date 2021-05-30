#include<bits/stdc++.h>
using namespace std;

const int LIMIT = 5e2+5;
int dp[LIMIT][250*502];
int mod = 1e9+7;

auto power = [&](int64_t a,int64_t b,int64_t mod){
    int64_t res = 1;
    while(1){
		if(b==0){
			break;
		}
		int64_t cnt = 1;
		int64_t curr = a % mod;
		while(cnt * 2 < b){
			curr = (curr%mod*curr%mod)%mod;
			cnt *= 2;
		}
		res = (res%mod*curr%mod)%mod;
		b -= cnt;
	}
	return (res%mod+mod)%mod;
};

auto ModInv = [&](int64_t a,int64_t mod){
	return power(a,mod-2,mod);
};

int go(int curr, int n, int sum, int target){
	if(curr > n){
		if(sum == target) return 1;
		else return 0;
	}
	if(dp[curr][sum]!=-1) return dp[curr][sum]%mod;
	int choice1 = go(curr+1,n,sum+curr,target);
	int choice2 = go(curr+1,n,sum,target);
	return (dp[curr][sum] = choice1+choice2)%=mod;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	{
		int n; cin >> n;
		memset(dp, -1, sizeof dp);
		if(n*(n+1)/2 % 2 == 1){
			cout << 0 << '\n';
			exit(0);
		}
		cout << ( go(1,n,0,n*(n+1)/4) * ModInv(2,mod) ) % mod ;
	}
}