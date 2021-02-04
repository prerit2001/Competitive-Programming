/*
*  Given heights of n towers and a value k.
*  We need to either increase or decrease
*  height of every tower by k (only once) 
*  where k > 0. The task is to minimize 
*  the difference between the heights of 
*  the longest and the shortest tower after
*  modifications, and output this difference.
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

	long long n,k;cin>>n>>k;
	long long a[n] {};
	for(long long i=0;i<n;i++)cin>>a[i];
 	sort(a,a+n);
    int mini = a[n-1]-a[0];
    if(k<=mini){
        int biggi = a[n-1]-k;
        int smalli = a[0]+k;
        if(biggi<smalli)swap(biggi,smalli);
        for(int i=1;i<n-1;i++){
            int i_smalli = a[i]-k;
            int i_biggi = a[i]+k;
            if(i_smalli>i_biggi)swap(i_smalli,i_biggi);
            if(i_smalli<smalli and i_biggi>biggi){
                if(biggi-i_smalli<=i_biggi-smalli)smalli = i_smalli;
                else biggi = i_biggi;
            }
        }
        mini = min(mini,biggi-smalli);
    }
    cout<<mini<<'\n';

	return 0;
}

/*
* Input : 
	N K
	A1 A2 A3 ... AN
* Output :
	Minimizing the Maximum Height
*/