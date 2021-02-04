/*
*  Largest Sum Contiguous Subarray Using Kadane's A;gorithms
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	long long n;cin>>n;
	vector<long long > v;
	for(int i=0;i<n;i++){
		long long temp;
		cin>>temp;
		if(i==0){
			v.push_back(temp);
			continue;
		}
		if(temp*v.back()>=0)v.back()+=temp;
		else v.push_back(temp);
	}
	long long max_so_far = 0, max_ending_here = 0; 
	n = v.size();
	if(n==1){
		cout<<max(0ll,v[0])<<'\n';
		return 0;
	}
	// Kadane's Algorithm
	for(int i=0;i<n;i++){
		max_ending_here += v[i];
		if(max_ending_here>=max_so_far){
			max_so_far = max_ending_here;
		}
		if(max_ending_here<=0){
			max_ending_here = 0;
		}
	}
	cout<<max_so_far<<'\n';

	return 0;
}


/*
* Input : 
	N
	A1 A2 A3 .... AN
* Output :
	Max Sum of Subarray
*/