#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>dp;
vector<int>st;
int coin(int n)
 {
   if(n<=0)
    {return 0;}
   else
    { auto it=dp.find(n);
      if(it!=dp.end())
       {return dp[n];}
      else
       { int least=INT_MAX;
         for(auto i:st)
          {
            if(n-i>=0)
             {
              least=min(least,coin(n-i));
             }
          }
         dp[n]=least+1;
         return dp[n]; 
       }   
    } 
 }
int main()
 {  st={1,3,6,10,15};
    int t;
    cin>>t;
    while(t--)
     { 
       int n;
       cin>>n;
       int coins=0;
       coins+=n/15;
       n%=15;
       if(n)
        {  
            if(coins)
             coins+=coin(n+15)-1;
            else 
             coins=coin(n); 
        }
       cout<<coins<<endl;
     } 
    return 0;
 }