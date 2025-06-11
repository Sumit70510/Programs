#include<bits/stdc++.h>
using namespace std;
int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n,ans=0;
       cin>>n;
       vector<int>arr(n);
       for(int i=0;i<n;i++)
         {cin>>arr[i];}
       vector<int>optimized;
       int i=0;
       while(arr[i]==0&&i<n)
        {i++;}
       int k=n-1;
       while(arr[k]==0&&k>0)
        {k--;}
       int zero=0; 
       for(;i<k;i++)  
        {optimized.push_back(arr[i]);
          if(arr[i]==0)
           {zero++;}
        }
       cout<<zero<<endl;
     } 
    return 0;
 }