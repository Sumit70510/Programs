#include<bits/stdc++.h>
using namespace std;
int main()
{  
    int t,n,k,temp;
    cin>>t;
    string s;
    while(t--)
    {
      cin>>n>>k;
      cin>>s;
      temp=k;
      int pre=-1,post=-1,flag=0;
      for(int i=0;i<n;i++)
      {   
         if(s[i]=='*'&&((i>0)?s[i-1]:'x')!='*')
         {pre=i;continue;}
         if(s[i]=='*'&&((i<n-1)?s[i+1]:'z')!='*')
         {post=i;}
         if((post-pre)>=k)
         {flag=1;}
      }
     if(flag)
     {cout<<"YES";}
     else
     {cout<<"NO";}
     cout<<endl;
    }
  return 0;
}