#include<bits/stdc++.h>
using namespace std;
int main()
{   int t,n,k;
    cin>>t;
    while(t--)
    {   long i,j,mini=0,mark1=0;
        bool flag=0;
        cin>>n>>k;
        long ht[n],s1=0,s2=0,ct=0;
        for(i=0;i<n;i++)
        {cin>>ht[i];}
        sort(ht,ht+n);
    ///////////////perfect number/////////////////////
         for(i=n-1;i>=0;i--)
         {  if(s1<k)
            { s1+=ht[i];j=i;ct++; }
           else
            { break; }
         }
        if(s1>=k&&i>0)
        { 
          i++;
          j--;
          int t1=i,t2=j,temp=-1,number=0,number1=0;
          
          while(i<n)
          { while(s1-ht[i]+ht[j]>=k&&j>temp&&j<t1)
             { j--;flag=1;}
             if(flag)
             {s1=s1-ht[i]+ht[j+1];ht[j+1]=-1;flag=0;}
             else
             { ht[i]=-1;}             
             i++;temp=j;
             j=t2;
          }            
         for(i=n-1;i>=0;i--)
          {if(ht[i]>0) 
            { if(s2<k)
               { s2+=ht[i];
                 ct++; }
              else
               { break; }
            } 
          }
         if(s2<k)
          {ct=-1;}
        } 
        else
        { ct=-1;     }
          
        cout<<ct<<endl;
    }
    return 0;
}