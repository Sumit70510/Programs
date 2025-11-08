#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int recursion(int ind,int pointing,int count,int n,string &str)
 {
    if(ind==n-1)
     {
       return count==0; 
     }
    if(dp[ind][pointing]!=-1)
     {
       return dp[ind][pointing]; 
     }
    bool left=false,right=false; 
    if(str[ind]=='0')
     {
       if(pointing)
        {
          if(count==1)
           {
            left = recursion(ind+1,0,0,n,str); 
           } 
          else
           {
             left = recursion(ind+1,0,count,n,str);
            //  right = recursion(ind+1,1,count,n,str);
           }  
        } 
       else 
        {
          left = recursion(ind+1,0,count,n,str);  
          right = recursion(ind+1,1,count,n,str);  
        } 
     }  
    else 
     {
       if(pointing)
        {
          left = recursion(ind+1,1,count+1,n,str);  
        }  
       else
        {
          left = recursion(ind+1,0,count,n,str);  
        } 
     } 
    return dp[ind][pointing] = left||right; 
 }

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n;
       cin>>n;
       string str;
       cin>>str;
       bool ans;
       dp=vector<vector<int>>(n,vector<int>(2,-1));
       ans=recursion(0,0,0,n,str);
       if(ans)
        {
         str="Yes"; 
        } 
       else
        {
         str="No"; 
        } 
       cout<<str<<endl;       
     } 
    return 0;
 }