#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	  long long int x,a=0,b=0,c=0,copy;
	  cin>>x;
	  copy=x;
	  vector<int> bits(27,0),position;
	  int count=0,ones=0;
	  while(copy)
	   {
	     if((x&(1<<count))!=0)    
	      {bits[count]=1;ones++;
	       position.push_back(count);    
	      }
	    count++;
	    copy>>=1;
	   }
	  int mask=1;
	  if(ones>=2)
	   { b=x;
	     a=x;
	     c=x;
	     mask=1<<position[0];
	     a&=(~mask);
	     mask=1<<position[1];
	     c&=(~mask);
	   }
	  else
	   {///////make ones//////////
	    b=x;a=x;c=x;
	    for(int i=0;i<27;i++)
	     { if(bits[i]!=1)
	        {bits[i]=1;
	         mask=1<<i;
	         a|=mask; break;
	        }
	     }
	    for(int i=0;i<27;i++)
	     { if(bits[i]!=1)
	        {mask=1<<i;
	         c|=mask; break;
	        }
	     }
	   }
	  cout<<a<<" "<<b<<" "<<c<<endl; 
	}
	return 0;
}

