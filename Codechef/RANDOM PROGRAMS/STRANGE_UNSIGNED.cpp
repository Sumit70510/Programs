#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	  long  int n,d,cases=0,ans=0;
	  cin>>n>>d;
	  if(d>0)
	   { cases=1;
	     for( long int i=0;i<10&&i<d;i++)
	       { cases=cases*2;}
	     for( long int i=0;(i<d-10)&&cases<=n;i++)
	      {cases=cases*3;}
	      
	   }
	   //ans=min(cases,n);
	   ans=cases;
	   cout<<ans<<endl;
	}
	return 0;
}