11#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n;
       string str;
       long temp;
       cin>>n;
       long ans=0;
       cin>>str;
       for(int i=0;i<str.length();i++)
        {
           if(str[i]=='@')
            {ans++;}
           else
            { if(str[i]=='*')
               {
                if(i+1<str.length()&&str[i+1]=='*')
                 {break;}
               }
            }  
        }    
       cout<<ans<<endl;
     } 
    return 0;
 }