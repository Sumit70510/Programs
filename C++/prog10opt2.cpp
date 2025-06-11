#include<bits/stdc++.h>
using namespace std;
int n,prime=1,lf=1;
#define ca(a,b) a%b
#define ca1(prime,j) if((prime%j==0)&&j!=1) return(func())
int func()
{  prime+=2;int j;
    for( j=lf;j<(prime/2);j+=2)
     {
       ca1(prime,j);
      }
    return prime;
}
bool check(long long b[],int &temp)
{
    for(int i=temp-1;i>=0;i--)
    {
        if(ca(b[i],(n+1))==ca(b[temp],(n+1)))
         {temp=i;prime-=2;return 1;}
    }
    return 0;
}
void countnumber(long long b[],long long p[],long long a[])
{
    for(int i=0;i<n;i++)
    { b[b[i]%n]+=n;}
}
int main()
{
   int t,i;
   cin>>t;
   while(t--)
	{
		int j;
	    cin>>n;
	   long long b[n],a[n],pos[n],pt[n];
	    for(i=0;i<n;i++)
	     {
           cin>>b[i];
           pt[i]=b[i];b[i]--;
	      }
	    countnumber(b,pt,a);
	    for( i=0;i<n;i++)
	    { if(b[i]-1!=i)
	      {pos[k]=b[i];

	       }
           else
           a[i]=primeno();
	    }
        for(i=0;i<n;i++)
	     cout<<a[i]<<" ";
	     cout<<endl;
	}
	return 0;
}
