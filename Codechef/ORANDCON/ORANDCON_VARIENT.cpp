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
	  int count=0,ones=0,k=0;
	  int binaryNum[27]={0},position[27];
	  while (copy > 0) {
		// storing remainder in binary array
	 	binaryNum[count] = copy % 2;
	 	if(binaryNum[count]==1)
	 	 {ones++;
	 	  position[k]=count;k++;    
	 	 }
	 	copy = copy / 2;
	   	count++;
	   }
       cout<<count<<endl;
       for(int i=count-1;i>=0;i--)
         {cout<<binaryNum[i]<<" ";}
       cout<<endl;  
	  int mask;
	  if(ones>=2)
	   {
	     mask=1<<position[0];
	     a&=(~mask);
         mask=1<<position[1];
         c&=(~mask);
	   }
	  else
	   {///////make ones//////////
	    int flag=1;
	    for(int i=count-1;i>=0;i--)
	     { if(binaryNum[i]!=1)
	        {binaryNum[i]=1;
	         mask=1<<i;
	         a|=mask;flag=0;break;
	        }
	     }
	    if(flag==1)
	     { mask=1<<count;
	       a|=mask;
           mask=1<<(count+1);
	       c|=mask;flag=2;
         }
        if(flag!=2)
	    { flag=1;
        for(int i=count-1;i>=0;i--)
	     { if(binaryNum[i]!=1)
	        {binaryNum[i]=1;
	         mask=1<<i;
	         c|=mask;flag=0;break;
	        }
	     }
	       if(flag==1)
	        { mask=1<<count;
	          c|=mask;
	        }
         }  
	   }
	  cout<<a<<" "<<b<<" "<<c<<endl; 
	}
	return 0;
}

