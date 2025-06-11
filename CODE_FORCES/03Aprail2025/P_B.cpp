#include<bits/stdc++.h>
using namespace std;

int main()
 {  int t;
    cin>>t;
    while(t--)
     { 
       long long n,k;
       long long x;
       cin>>n>>k>>x;
       vector<long long>arr(n);
       for(long long i=0;i<n;i++)
        {cin>>arr[i];}
       long long temp=accumulate(arr.begin(),arr.end(),0LL),sum=temp*k;
       long long ans=0,f=0;
       if(sum>=x)
        {f=1;} 
       while(sum>=x)
         {
            ans+=n;
            sum-=temp;
         }     
        if(f) 
         {sum+=temp;}
        ans-=n;
        if(ans<0)
         {ans=0;}
        for(long long j=0;j<n;j++)  
          {
           if(sum>=x)
            {
             ans++;
             sum=sum-arr[j];   
            }
           else
            {break;}
           } 
       cout<<ans<<endl;
     } 
    return 0;
 }