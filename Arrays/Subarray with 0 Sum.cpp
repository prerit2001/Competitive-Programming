/*
https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
*/

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
    	if (subArrayExists(arr, n))
			cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

bool subArrayExists(int arr[], int n)
{
    set<int> s;
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]==0)return true;
            s.insert(arr[i]);
        }
        else{
            arr[i]+=arr[i-1];
            if(!arr[i])return true;
            else if(s.count(arr[i]))return true;
            s.insert(arr[i]);
        }
    }
    return false;
}
