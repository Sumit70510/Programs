#include<bits/stdc++.h>
using namespace std;
int main()
 {
   int n=3; 
   vector<int>arr={2,1,3}; 
   bool flag=1; 
   for(int i=0;i<arr.size();i++)
    {
      for(int j=0;j<arr.size();j++)
       {
         if(i!=j)
          {
            if(arr[j]%arr[i]==0)
             { if(j+1<arr.size()&&i+1<arr.size())
                {
                  if(arr[j+1]%arr[i+1]==0)
                   {flag=0;
                    cout<<i<<","<<j;
                   break;}  
                }
             } 
          }
       }
     }
       if(flag==0)
        {cout<<": Wrong"<<endl;}
       else 
        {cout<<"RIGHT"<<endl;}   

   return 0; 
 }