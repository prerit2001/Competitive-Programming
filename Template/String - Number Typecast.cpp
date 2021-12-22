#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000;

struct Number{
	string s;

	bool operator < (const Number &b) const{
		if (this->s.size() == b.s.size()){
			return this->s < b.s;
		}

		return this->s.size() < b.s.size();
	}
};

Number INF = {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"};
Number dp[N + 1][2];

Number solve(int n, bool positive) {
	if (n < 0) {
		return INF;
	}

	if (n == 0) {
		return {""};
	}

	if (!dp[n][positive].s.empty()) {
		return dp[n][positive];
	}

	dp[n][positive] = INF;

	if (positive) {
		dp[n][positive] = min(dp[n][positive], {"0" + solve(n - 6, true).s});
	}

	dp[n][positive] = min(dp[n][positive], {"1" + solve(n - 2, true).s});
	dp[n][positive] = min(dp[n][positive], {"2" + solve(n - 5, true).s});
	dp[n][positive] = min(dp[n][positive], {"4" + solve(n - 4, true).s});
	dp[n][positive] = min(dp[n][positive], {"6" + solve(n - 6, true).s});
	dp[n][positive] = min(dp[n][positive], {"7" + solve(n - 3, true).s});
	dp[n][positive] = min(dp[n][positive], {"8" + solve(n - 7, true).s});

	return dp[n][positive];
}

int main() {
	int t, n, i;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		printf("%s ", solve(n, false).s.c_str());

		if (n % 2 != 0) {
			printf("7");
			n -= 3;
		}
		
		for (i = 0; i < n / 2; i++){
			printf("1");
		}

		printf("\n");
	}

	return 0;
}