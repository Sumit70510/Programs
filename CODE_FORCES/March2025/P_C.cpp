#include<bits/stdc++.h>
using namespace std;

int main()
 {  int t;
    cin>>t;
    while(t--)
     { 
       int n;
       cin>>n;
       vector<int>data(n,0);
       vector<bool>visited(n+1,false);
       bool flag=true;

       for(int i=0;i<n;i++)
        {
          int valueIndex=(i*2 + 1)%(n);
          if(valueIndex==0)
           {valueIndex=n;}
          if(visited[valueIndex]==true) 
           {flag=false;break;}
          else 
           {
             visited[valueIndex]=true;
             data[i]=valueIndex;
           } 
        }
       if(flag)
        {for(auto &i:data)
         {cout<<i<<" ";}
        }
       else 
        {cout<<"-1";}
       cout<<endl; 
     } 
    return 0;
 }