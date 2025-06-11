#include<bits/stdc++.h>
using namespace std;
int n,prime=1,lf=1;
int primeno()
{
	prime+=2;int j;
    for( j=lf;j<(prime/2);j+=2)
     {
        if((prime%j==0)&&j!=1)
        return(primeno());
     } if(j>2)
       lf=j-2;
    return prime;
}
int main()
{
   int t,i;
   cin>>t;
   while(t--)
	{
		int j;
	    cin>>n;
	   long long b[n],a[n],pos[n];
	    for(i=0;i<n;i++)
        {cin>>b[i];a[i]=0;}
		for(i=0;i<n;i++)
		{   if(b[i]-1==i)
			{ if(a[i])
			   {a[i]*=2;}
			  else
			   {a[i]=primeno();}
			}
			else
			{   if(a[b[i]-1])
				{a[b[i]-1]*=2;}
				 else
				{a[b[i]-1]=primeno();}
				a[i]=a[b[i]-1];
			}
			cout<<a[i]<<" ";
		}
     cout<<endl;
	}cin>>n;
	return 0;
}

