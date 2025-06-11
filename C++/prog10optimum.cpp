#include<bits/stdc++.h>
using namespace std;
int n,prime=1;
int func(long long a,int d)
{  prime+=2;int j;
    for( j=1;j<(prime/2);j+=2)
     {
       if((prime%j==0)&&j!=1)
       return(func(a,d));
     }
    return prime;
}
bool check(long long b[],long long var,int &temp)
{
    for(int i=temp-1;i>=0;i--)
    {
        if((b[i]%(n+1))==var%(n+1))
         {temp=i;prime-=2;return 1;}
    }
    return 0;
}
int main()
{
   int t,i;
   cin>>t;
   while(t--)
	{
		int j;
	    cin>>n;
	   long long b[n],a[n];
	    for(i=0;i<n;i++)
	     cin>>b[i];
        for(i=0;i<n;i++)
	     {  j=i;
	        b[i]+=(n+1)*func(b[i],i);
	        if(check(b,b[i],j))
 	        {a[i]=b[j]/(n+1)*2;}
	        else
	        a[i]=b[i]/(n+1);
	     }
	    for(i=0;i<n;i++)
	     cout<<a[i]<<" ";
	     cout<<endl;
	}cin>>t;
	return 0;
}
