/*
*  You want to maximize your profit by choosing 
*  a single day to buy one stock and choosing a 
*  different day in the future to sell that stock.
*  Return the maximum profit you can achieve from 
*  this transaction. If you cannot achieve any profit,
*  return 0.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	long long n;cin>>n;
	long long a[n];
	for(long long i = 0;i<n;i++)cin>>a[i];
	long long mini[n],maxi[n];
	memset( mini, 0, n*sizeof(int) );
    memset( maxi, 0, n*sizeof(int) );
	mini[0] = a[0], maxi[n-1]=a[n-1];
	for(long long i=1;i<n;i++){
		mini[i] = min(mini[i-1],a[i]);
		maxi[n-i-1] = max(maxi[n-i],a[n-i-1]);
	} 
	long long ans = -1;
	for(long long i=1;i<n;i++){
		ans = max(ans,maxi[i]-mini[i-1]);
	}	
	cout<<max(0LL,ans)<<'\n';

}


/*
* Input : 
	N
	A1 A2 A3 .... AN
* Output :
	Max Profit
*/