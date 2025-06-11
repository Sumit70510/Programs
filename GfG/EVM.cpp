#include <bits/stdc++.h>
using namespace std;

int main() {
	long int t;
	cin>>t;
	while(t--)
	{ int a,b,c,p,q,r;
	  cin>>a>>b>>c>>p>>q>>r;
	  float vote_gained,total_votes;
	  vote_gained=a+b+c;
	  total_votes=p+q+r;
	  string ans;
	  if(vote_gained>(total_votes/2.0))
	   {ans="YES";}
	  else
	   { if(p>q)
	      { 
	        if(p>r)
	         {
	          vote_gained-=a;
	          vote_gained+=p;
	         }
	        else
	         {
	           vote_gained-=c;
	           vote_gained+=r;  
	         }
	      }
	     else
	      {
	        if(q>r)
	         {
	          vote_gained-=b;
	          vote_gained+=q;      
	         }
	        else
	         {
	          vote_gained-=c;
	          vote_gained+=r;  
	         }
	      }
	     if(vote_gained>(total_votes/2.0))
	      {ans="YES";}
	     else
	      {ans="NO";}
	   }
	  cout<<ans<<endl;
	}
	return 0;
}

