#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int x,y;
       cin>>x>>y;
       if(x==0&&y==0)
        {cout<<0<<endl;continue;}
       if(x==y||y==1)
        {cout<<-1<<endl;continue;}
       if(x<y)
        {cout<<2<<endl;continue;}
       if((x>(1+y)))
        {
          cout<<3<<endl;continue;  
        }   
       cout<<-1<<endl; 
     } 
    return 0;
 }