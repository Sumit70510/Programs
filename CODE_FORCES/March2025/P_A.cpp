#include<bits/stdc++.h>
using namespace std;

int main()
 {  int t;
    cin>>t;
    while(t--)
     { 
       int n;
       cin>>n;
       vector<int>a(n);
       for(int i=0;i<n;i++) 
        {
         cin>>a[i];
        }
       vector<int>hash(10,0),target(10,0);
       target[0]=3;
       target[1]=1;
       target[2]=2;
       target[3]=1;
       target[5]=1;
       int ans=0;
       for(int i=0;i<n;i++)
        {
          target[a[i]]=max(--target[a[i]],0);
          if(target==hash) 
           {ans=i+1;break;} 
        } 
        cout<<ans<<endl;
     } 
    return 0;
 }