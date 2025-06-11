#include <bits/stdc++.h>
using namespace std;
bool ispowerof2(int n)
 {return (n&&!(n&(n-1)));}
int countbit(int n)
 { int bits=0;
   while(n>>=1)
   {bits++;}
   return bits; } 
void judge(int element,int &sumfactor,int &multiplyfactor)
{
   int n,ans=0,ans2=0,sum=0,sum2=0;
   n=element;
  if(n>1) 
   {/////////nearest power of 2
   int bit=countbit(element);
   ans=((abs((1<<bit)-n)<=abs((1<<bit+1)-n))?bit:bit+1);
   sum=abs((1<<ans)-n);
   sum++;
   while(n)
    { if(n%2==0)
       { if(ispowerof2(n))
         { ans2+=countbit(n);
           n=0;break;
         }
         else 
          {ans2++; n/=2;}      
       }
      else 
       {sum2++;n--;}       
     }
     sum2++;
   if(sum+ans<=(sum2+ans2))
    {multiplyfactor=ans;
     sumfactor=sum;
     element-=sum+1;
    }
   else
    {multiplyfactor=ans2; 
     sumfactor=sum2;
     element-=sum2+1;
    }
   }
   else
    { sumfactor=1;
      multiplyfactor=0;    
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
      int arr[n],answer=0;
      int factor=0,factorsum=0,maxfactor=0;
	  for(int i=0;i<n;i++)
	   { cin>>arr[i];}
	  for(int i=0;i<n;i++)
	   { if(arr[i]!=0)
	      {judge(arr[i],factorsum,factor);
	       maxfactor=max(maxfactor,factor);
	       answer+=factorsum;
	      }    
	   }
	   answer+=maxfactor; 
	  cout<<answer<<endl;
	}
	return 0;
}

