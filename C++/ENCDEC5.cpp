#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ long long int  n,m;
	  cin>>n;
	  long long int arr[n];
	  for(long i=0;i<n;i++)
	   { cin>>arr[i];
	      arr[i]=arr[i]+  arr[i]%3;
	   }
	   cin>>m;
	   sort(arr,arr+n);
	   int i=0,caught=-1,smaller=-1,bigger=-1;
	   while(arr[i]<m&&i<n)
	   {if(arr[i]==m)
	       {caught=i;break;}
	       i++;
	   }i--;
	   if(caught==-1)
	    { if(i>0&&i<n-1)
	      {
	          bigger=arr[i+1];
	          smaller=arr[i];
	      }
	      else
	      {
	          if(i==0)
	          {
	              bigger=arr[0];
	          }
	          else
	           smaller=arr[i];
	      }
	    }
	   else
	    {
	      if(caught>0&&caught<=n-2)
	      {bigger=arr[caught+1];
	       smaller=arr[caught-1];
	      }
	      else
	       {
	           if(caught==0)
	           {bigger=arr[1];}
	           else
	           {smaller=arr[n-2];}
	       }
	    }
	    cout<<smaller<<' '<<bigger<<endl;
	}
	return 0;
}

