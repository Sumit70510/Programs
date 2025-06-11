#include<bits/stdc++.h>
using namespace std;
int main()
{
   int flag=1, n=10,key,j;
    int z[]={2,1,3,4,5,6,7,8,9,10};
      for(int i=n-3;(i>=0)&&flag;i--)
       {
           key=z[i];
           j=i+1;
           while(j<=n-2&&z[j]<key)
            { z[j-1]=z[j];
              j++;flag=0;
            }
           z[j-1]=key;    
       }
     for(auto s:z)
      {cout<<s<<" ";}  
  return 0;
}