#include<bits/stdc++.h>
using namespace std;

int main()
 {  int t;
    cin>>t;
    while(t--)
     { 
       int n,k;
       long long x;
       cin>>n>>k>>x;
       vector<long long>arr(n);
       for(int i=0;i<n;i++)
        {cin>>arr[i];}
       long long sum=accumulate(arr.begin(),arr.end(),0)*k;
       int ans=0;
       for(int i=0;i<k;i++)
        {
          for(int j=0;j<n;j++)  
           {
            if(sum>=x)
            {
             ans++;
             sum-=arr[j];   
            }
           else
           {i=k;break;}
          }
        } 
       cout<<ans<<endl;
     } 
    return 0;
 }