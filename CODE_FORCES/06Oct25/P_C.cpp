#include<bits/stdc++.h>
using namespace std;

int recursion(int ind,int canRemove,int prev,int a,int b,string &s)
 {
    if(a==b)
     {return ((a!=0)? 0 :1e9 );}
     
    if(ind==s.length())
     {
       if(a==b) 
        {return 0;}
       return 1e9; 
     }
     
    int skip = recursion(ind+1,canRemove,-1,a,b,s);
    int choose=1e9;
    if(prev==ind-1||canRemove)
     {
       if(s[ind]=='a')
        {a--;}
       else
        {b--;}  
       choose = 1 + recursion(ind+1,0,ind,a,b,s);   
     }
    return min(skip,choose);
 }

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     int n;
     string s;
     cin>>n>>s;
     long ans=0;
     int ct_a=0,ct_b=0;
     for(int i=0;i<n;i++)
      {
        if(s[i]=='a')
         {ct_a++;}
        else
         {ct_b++;} 
      }
     ans=recursion(0,1,-1,ct_a,ct_b,s);
     if(ans>=1e9)
      {ans=-1;}
     cout<<ans<<endl;
   }   
  return 0;  
}