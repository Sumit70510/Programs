#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n;
       vector<long>arr;
       long temp;
       cin>>n;
       long ans=0;
       for(int i=0;i<2*n;i++)
        {
          cin>>temp;
          arr.push_back(temp);  
        }
       sort(arr.begin(),arr.end());
       for(int i=0;i<arr.size();i+=2)
        {ans+=arr[i];}    
       cout<<ans<<endl;
     } 
    return 0;
 }