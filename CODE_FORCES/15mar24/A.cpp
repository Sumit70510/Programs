#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n;
       cin>>n;
       if(n%2)
        {cout<<"NO"<<endl;continue;}
       string ans;
       char ch='A';
       int t=0;
        while(n--)
           { t++;
             ans+=ch;
             if(t==2)
              {ch++;t=0;}
           }      
       cout<<"YES"<<endl;
       cout<<ans<<endl;
     } 
    return 0;
 }