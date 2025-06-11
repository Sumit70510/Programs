#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	   long long n,ans=0;
	   cin>>n;
	   float a[n+1],t1=1,t2;
	   for(long long i=1;i<=n;i++)
	    {cin>>a[i];}
	  sort(a,a+n,std::greater<>());
	   for(int i=1;i<n;i++)
	   { t2=0;
	     if(a[i]!=a[i+1])
	     {t2=(n-i);
	      ans+=max(t1*t2,t2);
         // cout<<ans <<endl;
	      t1=1;
	     }
	    else
	     {t1++;}
         cout<<i<<endl;
	   }cout<<"pause";
	 //  cout<<ans*2<<endl; 
	}
	return 0;
	
}


