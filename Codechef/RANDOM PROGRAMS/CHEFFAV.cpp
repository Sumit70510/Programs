#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{ 
	  long long int n;
	  string s,code="code",chef="chef",ans="WA";
	  int count_code=0,count_chef=0,init_code=0,init_chef=0;
	  cin>>n>>s;
	  for(int i=0;i<n;i++)
	  {
	    count_code=s.find(code,init_code);
	    count_chef=s.find(chef,init_chef);
	    if(count_code!=-1&&count_chef!=-1)
	    { if(count_code>count_chef)
	       {ans="WA";break;}
	      else
	       {  ans="AC";
	          init_chef=count_chef+1;
	          init_code=count_code+1;
	       }
	    }
	    else
	     {    if(count_chef==-1&&count_code!=-1)
	           {ans="AC";}
	     }
	  }
	  cout<<ans<<endl;
	}
	return 0;
}

