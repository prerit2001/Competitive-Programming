#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{	
	long long n;
	cin>>n;
	long long price[n];
	for(int i=0;i<n;i++)
		cin>>price[i];
	long long profit[n] = {};
	long long price_maxi = price[n-1];
	long long price_mini = price[0];
	for(int i=n-2;i>=0;i--){
		price_maxi = max(price_maxi,price[i]);
		profit[i] = max(profit[i+1],price_maxi-price[i]);
	}
	for(int i=1;i<n;i++){
		price_mini = min(price_mini,price[i]);
		profit[i] = max(profit[i-1],profit[i]+(price[i]-price_mini));
	}
	cout<<profit[n-1]<<endl;

	return 0;
}