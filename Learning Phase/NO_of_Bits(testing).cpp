#include<bits/stdc++.h>
using namespace std;
int m1(int n)
{ int bit=floor(log2(n));
  return bit;  
}
int m2(int n)
{ int count=0;
  while(n)
   {count++;n>>=1;}
  return count;
}int ct;
void compare(int m1,int m2)
 {
   if(m1!=m2)
    {cout<<m1<<" : "<<m2<<endl;ct++;}   
 }
void genrate(int bits)
 {ct=0;
  for(int i=0;i<((1<<bits+1)-1);i++)
   { compare(m1(1),m2(i)); }
  if(ct==0)
   {cout<<"BOTH ARE CORRECT :)"<<endl;}
  else
   {cout<<"TESTCASE FAILED :(  = "<<ct<<endl;}  
 } 
int main()
{ genrate(30);
  return 0;  
}