/*
*  Count of Even Xored Subarray
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	long long n;cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	bool flag = false;
	long long cnt = 0;
	long long sum_true_flag = 0;
	long long sum_false_flag = 0;
	long long sum = 0;
	bool glab = false;
	long long next = 0;
	for(int i=n-1;i>=0;i--){
		if(a[i]&1){	
			long long diff = cnt*(cnt+1)/2;
			sum+=diff;
			if(!glab){
				sum_false_flag+=cnt+1;
				flag=true;
			}
			else{
				if(flag){
					sum+=sum_false_flag-next-1;
					sum+=next+1;
					sum+=cnt*sum_true_flag;
					sum_true_flag+=cnt+1;
					flag=false;
				}
				else{
					sum+=sum_true_flag-next-1;
					sum+=next+1;
					sum+=cnt*sum_false_flag;
					sum_false_flag+=cnt+1;
					flag=true;
				}
			}
			next=cnt;
			cnt = 0;
			glab = true;
		}
		else ++cnt;
	}
	long long diff = cnt*(cnt+1)/2;
	sum+=diff;
	sum+=cnt*(!flag ? sum_false_flag : sum_true_flag);
	cout<<sum<<'\n';
	
	return 0;
}

/*
* Input : 
	N
	A1 A2 A3 .... AN
* Output :
	Max Profit
*/