#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n;
       cin>>n;
       vector<int>arr(n);
       for(int i=0;i<n;i++)
        {cin>>arr[i];}
       sort(arr.begin(),arr.end());
       int g1=arr[n-1],g2=arr[n-2];
       int s1=arr[0],s2=arr[1]; 
       int ans=(abs(g1-s1)+abs(g1-s2)+abs(g2-s1)+abs(g2-s2)); 
       cout<<ans<<endl;
     } 
    return 0;
 }