#include <bits/stdc++.h>
using namespace std;

int main() {
	long t;
	cin>>t;
	while(t--)
	{ 
	  long n,k;
	  long h[n],mini=0,rem=0,answer=0;
	  cin>>n>>k;
	  for(long i=0;i<n;i++)
	  {  cin>>h[i];
	     if(rem==0)
	     {mini=h[i];}
	     else
	     {mini=min(mini,h[i]);}
	     rem++;
	     if(rem==k)
         {rem=0;answer+=mini;}	     
	  }
	  cout<<answer<<endl;
	}
	return 0;
}


