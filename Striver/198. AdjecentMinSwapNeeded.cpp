#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define scan(a,n) for(long long int index=0;index<n;index++) cin>>a[index];
#define print(a,n) for(long long int index=0;index<n;index++) cout<<a[index]<<" ";cout<<endl;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vi vector<int>
#define vli vector<long long int>
#define vlli vector<pair<long long int,long long int>>
#define all(n) n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()


ll sub(ll x,ll y){  ll z=(x-y)%mod;if(z<0) z+=mod; return z;}
ll add(ll x,ll y){  return (x+y)%mod;}
ll mul(ll x,ll y){  return (x*y)%mod;}
ll power(ll x, ll y) {ll res = 1; x %= mod;
 while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}

 
int main() {
  fast;
  ll n;
  cin>>n;
  vector<char> vv(n);
  scan(vv,n);
  ll i,j,x,y;
  char a,b;
  cin>>a>>b;
  vli v(n);


  for(i=0;i<n;i++){
       if(vv[i]==a) x=1;
       else if(vv[i]==b) x=2;
       else x=0;
       v[i]=x;
  } 
  vli d(n);
  if(v[n-1]) d[n-1]=1;
  for(i=n-2;i>=0;i--){
    d[i]=d[i+1];
    if(v[i]) d[i]++;
  }
  // for(ll i = 0; i < n; i ++){
  //   cout << v[i] << " ";
  // }
  // cout << endl;
  // for(ll i = 0; i < n; i ++){
  //   cout << d[i] << " ";
  // }
  // cout << endl;
  ll ans=0;
  vli dp;
  x=0;
  for(i=0;i<n;i++){
    if(v[i]==0){ 
      ans+=min(x,d[i]);
    }else{
      dp.pb(v[i]);
      x++;
    }
  }

  // for(ll i = 0; i < dp.size(); i ++){
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
  ll an=0,as=0;;
  x=0;
  for(i=0;i<dp.size();i++){
     if(dp[i]==1){
      x++;
     }else{
      an+=x;
     }
  }
  x=0;
  for(i=0;i<dp.size();i++){
     if(dp[i]==2){
      x++;
     }else{
      as+=x;
     }
  }

  ans+=min(an,as);
  cout<<ans<<endl;



return 0;    
 }