#include<bits/stdc++.h>
using namespace std;

int main()
 {  int t;
    cin>>t;
    while(t--)
     { 
       int n,x;
       cin>>n>>x;
       vector<int>a(n);
       int ans=0;
       for(int i=0;i<n;i++)
        {
         cin>>a[i];
        }
       sort(a.begin(),a.end());
       int sz=1;
       for(int i=n-1;i>=0;i--)
        {
          if(a[i]*sz>=x)
           {ans++;sz=1;}
          else
           {sz++;} 
        } 
       cout<<ans<<endl;
     } 
    return 0;
 }