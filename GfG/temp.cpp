#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    
    for(int i=0;i<5;i++)
    {cin>>arr[i];}
     int n=4;
     int i=n-1;
    for(;i+(n-1-i)>=n-1;i--)
    {cout<<i<<endl;}
}