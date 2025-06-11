#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<'[';
    int n=1e5;
    for(int i=0;i<n;i++)
     {
       if(i%2==0) 
        cout<<"2";
       else 
        cout<<"1";
       if(i!=n-1)
        {cout<<",";}  
     }
     cout<<']';
    return 0;
}