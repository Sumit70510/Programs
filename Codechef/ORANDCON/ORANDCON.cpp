#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	  long long int x,a=0,b=0,c=0,copy;
	  cin>>x;
	  copy=a=b=c=x;
	  vector<int> bits(27,0),position;
	  int count=0,ones=0;
	  int mask;
	  while(copy)
	   {mask=1<<count;
		if((x&mask)!=0)
		 {bits[count]=1;
		  ones++;position.push_back(count);}    
	    count++;
	    copy>>=1;
	   }	
	  if(ones>=2)
	   { //destroy ones
	     mask=1<<position[0];
	     a&=(~mask);
	     mask=1<<position[1];
	     c&=(~mask);
	   }
	  else
	   {
		for(int i=0;i<=26;i++)
	      { if(bits[i]!=1&&a==x)
	        {bits[i]=1;
	         mask=1<<(i);
	         a|=mask;
	        }
            if(bits[i]!=1&&c==x)
	        {mask=1<<(i);
	         c|=mask;break;
	        }
	      }
	   }
	  cout<<a<<" "<<b<<" "<<c<<endl; 
	}
	return 0;
}