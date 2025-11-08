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
       vector<int>ans(2*n);
       for(int i=n+1;i<=2*n;i++)
        {
            ans[i-1]=i-n;
        }
       ans[n-1]=n;
       for(int i=0;i<n-1;i++)
        {
          ans[i]=n-i-1;  
        }
       for(auto &i:ans)
        {
          cout<<i<<" ";  
        }
       cout<<endl;
     } 
    return 0;
 }