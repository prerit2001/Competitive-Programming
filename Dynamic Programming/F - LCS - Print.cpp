#include<bits/stdc++.h>
using namespace std;

int i,j;
string s1,s2;
int64_t dp2[3005][3005];

int64_t go(int64_t curr1,int64_t curr2){
	if(curr1 >= s1.size() or curr2 >= s2.size()){
		return 0;
	}
	if(dp2[curr1][curr2] != -1){
		return dp2[curr1][curr2];
	}
	int64_t choice1=0,choice2=0,choice3=0;
	if(s1[curr1] == s2[curr2]){
		choice1 = 1+go(curr1+1,curr2+1);
	}
	choice2 = go(curr1+1,curr2);
	choice3 = go(curr1,curr2+1);
	return dp2[curr1][curr2] = max({choice1,choice2,choice3});

}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING PRACTICE/input.txt", "r", stdin); 
	freopen("E:/CODING PRACTICE/output.txt", "w", stdout); 
	#endif

	int64_t t=1;
	// cin>>t;
	while(t--){
		cin>>s1>>s2;
		memset(dp2,-1,sizeof(dp2));
		go(0,0);
		int64_t curr1 = 0,curr2 = 0;
		string s = "";
		while(curr1 < s1.size() and curr2 < s2.size()){
			if(s1[curr1] == s2[curr2]){
				s += s1[curr1];
				curr1++,curr2++;
				continue;
			}
			if(dp2[curr1+1][curr2] >= dp2[curr1][curr2+1]){
				curr1++;
				continue;
			}
			if(dp2[curr1+1][curr2] < dp2[curr1][curr2+1]){
				curr2++;
				continue;
			}
		}
		cout<<s;
	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}