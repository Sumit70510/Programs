#include<bits/stdc++.h>
using namespace std;

int main()
 {  int t;
    cin>>t;
    while(t--)
     { 
       int n,m,k;
       cin>>n>>m>>k;
       k = (k/n) + (k%n?1:0);
       int minus= m-k + 1;
       int ans = k/minus + (k%minus?1:0); 
       cout<<ans<<endl; 
     } 
    return 0;
 }