#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		long long int PowMod(long long int a,long long int b,long long int mod){
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
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}