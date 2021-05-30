#include<bits/stdc++.h>
using namespace std;

const int64_t LIMIT = 5e3+5;
string a,b;
int64_t dp[LIMIT][LIMIT];

int64_t go(int64_t curr_a, int64_t curr_b){
	if(curr_a == a.size() or curr_b == b.size()){
		if(curr_a == a.size() and curr_b == b.size()) return 0;
		else if(curr_a == a.size()) return b.size()-curr_b;
		else return a.size()-curr_a;
	}

	if(dp[curr_a][curr_b]!=-1) return dp[curr_a][curr_b];

	int64_t choice1 = 1+go(curr_a+1,curr_b);
	int64_t choice2 = 1+go(curr_a,curr_b+1);
	int64_t choice3 = 1+go(curr_a+1,curr_b+1);
	int64_t choice4 = 1e8;
	if(a[curr_a] == b[curr_b]){
		choice4 = go(curr_a+1,curr_b+1);
	}

	return dp[curr_a][curr_b] = min({choice1,choice2,choice3,choice4});
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	int64_t i,j,t=1;
	// cin>>t;
	while(t--){
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		cout << go(0,0);
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}