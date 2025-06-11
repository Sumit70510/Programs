#include<bits/stdc++.h>
using namespace std;
int m1(int n)
{ if(n>0)
  return (log2(n)+1);
  else 
  return 0;
}
int m2(int n)
{ long long count=0;
  while(n)
   {count++;n>>=1;}
  return count;
}int ct;
void compare(int m1,int m2,int i)
 {
   if(m1!=m2)
    {cout<<"i : "<<i<<"\n"<<m1<<" : "<<m2<<endl;ct++;}   
 }
void genrate(int bits)
 {ct=0;
  for(int i=0;i<(1<<bits)-1;i++)
   { compare(m1(i),m2(i),i); }
  if(ct==0)
   {cout<<"BOTH ARE CORRECT :)"<<endl;}
  else
   {cout<<"TESTCASE FAILED :(  = "<<ct<<endl;}  
 } 
int main()
{ genrate(29);
  return 0;  
}