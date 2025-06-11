#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       int n,temp,ans=0;
       cin>>n;
       vector<int> arr(n);
       for(int i=0;i<n;i++)
        {cin>>temp;
         arr[i]=temp;
        }
       ans=arr[0];
       for(int i=1;i<n;i++)
        {
            if(arr[i]>ans)
             {ans=arr[i];}
            else
             {
                int j=2;
                temp=arr[i];
                while(temp<=ans)
                 {
                    temp=arr[i]*j;
                    j++;
                 }
                ans=temp;
             } 
        }
       cout<<ans<<endl;
     } 
    return 0;
 }