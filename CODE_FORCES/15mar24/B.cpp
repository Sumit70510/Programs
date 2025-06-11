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
       vector<int>ans(n),flag(n,1),f2(n,1);
       for(int i=0;i<n;i++)
        {
           cin>>ans[i]; 
        }
        int mx=INT_MIN;
        bool f=1;
        int prv=ans[0]%10;
        for(int j=0;j<n;j++)
         {
          if(ans[j]/10>ans[j]%10)
            {   
             flag[j]=0;
            } 
           if(ans[j]%10<prv)
               {f2[j]=0;}
              prv=ans[j]%10;  
         } 
        auto it=flag.begin(); 
        for(int i=0;i<n-1;i++)
         {
            if(ans[i]>ans[i+1])
             { auto z=it+i+1;
               if(find(it,z,0)!=z)
                {cout<<"NO"<<endl;f=0;break;}
               else 
                 {
                    if(find(f2.begin(),f2.begin()+i+1,0)!=find(it,it+i+1,1))
                     {cout<<"NO"<<endl;f=0;break;}
                 }     
             }
         }
        if(f) 
         {cout<<"YES"<<endl;} 
     } 
    return 0;
 }