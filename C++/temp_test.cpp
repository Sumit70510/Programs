#include<bits/stdc++.h>
using namespace std;
int main()
 {
int n;
cin>>n;
vector<string>str(n);
for(int i=0;i<n;i++)
 {cin>>str[i];}

int max_len=INT_MIN;
string ans="";
bool f=0;
int mx=0,k=0;  
for(int i=0;i<n;i++)
 {
   if(str[i].length()>mx)
    {ans=str[i];
     mx=str[i].length();
    }
 }
for(int i=1;i<n;i++)
 {
   if(k<str[i].length()&&k<str[i-1].length())
    {
     if(str[i][k]!=str[i-1][k])
      {f=1;}
     else 
      {k++;}
    }
   else 
     {break;} 
    if(f)
     {
       break; 
     }  
    if(i==n-1)
     {i=0;} 
 } 
string res="";
for(int i=k;i<ans.length();i++)
 {res=ans[i];}
cout<<res<<endl; 

return 0;
}
