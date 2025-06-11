#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y,n,k;
	    cin>>x>>y>>k>>n;
        if(max(x-y,y-x)>k)	  
	     { if(max(x-y,y-x)%k==0&&k>1)
	       {cout<<"YES";}
	       else
	       {  if(k==1)
	          {
	             if(max(x-y,y-x)%2!=0)
	             {cout<<"NO";}
	             else
	              {cout<<"YES";}
	          }
	          else
	          {cout<<"NO";}
	       }
	     }
	     else
	     {cout<<"NO";}
	     cout<<endl;
	}
		return 0;
}
