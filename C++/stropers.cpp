#include<bits/stdc++.h>
using namespace std;
int main() 
{   short t;
    cin>>t;
    while(t--)
    {
      string s;
      cin>>s;
      int l=s.length(),n,ct=0,trk=0;
      n=l*((l+1)/2);
      string c[n],x,r;
      for(int i=0;i<l;i++)
       {
         for(int j=i;j<l;j++)
         {
             for(int k=i;k<=j;k++)
             { 
                 c[trk]+=s[k];
             }trk++;
         }
       }
      for(int i=0;i<n;i++)
       {
         for(int j=i+1;j<n;j++)
         { if(!c[i].compare(c[j]))
            {c[j].clear();}
         }
       } 
      for(int i=0;i<n;i++)
       {
         if(!c[i].empty())
         { cout<<c[i]<<endl;ct++;}
       } 
        cout<<"ct :"<<ct<<"\n"<<endl;
    }
    
	return 0;
}
