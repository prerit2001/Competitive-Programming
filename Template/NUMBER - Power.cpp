int power(int a,int b,int mod){
    int res = 1;
    while(1){
		if(b==0){
			break;
		}
		int cnt = 1;
		int curr = a % mod;
		while(cnt * 2 < b){
			curr = (curr%mod*curr%mod)%mod;
			cnt *= 2;
		}
		res = (res%mod*curr%mod)%mod;
		b -= cnt;
	}
	return (res%mod+mod)%mod;
};