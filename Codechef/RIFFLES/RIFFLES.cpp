#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	//cin>>t;
	t=1;
	while(t--)
	{ long long int k;
	  int n;
	  //cin>>n;
	  n=32;
	   int rep_factor=(n-2);
	   vector<int> arr(n+1,0);
	   vector<int> copy(n+1,0);
	   for(int i=1;i<=n;i++)
	   {arr[i]=i;}
	   copy=arr;
	  /* k=k%rep_factor;
	      int reverse=0;
	   if(rep_factor/2<k)
	    {reverse=1;
	     k=rep_factor-k;
	    }*/k=1;
	  while(k!=0)
	   {
	      for(int i=2,j=3;i<=n/2;i++,j+=2)
	        { copy[i]=arr[j];}
	       for(int i= n/2 + 1,j=2;i<n;i++,j+=2)
	        { copy[i]=arr[j];}

		 arr=copy;
	  for(int i=1;i<=n;i++)
	   {cout<<copy[i]<<" ";}
	  cout<<endl;
         cin>>k;
	   }

	}
  return 0;
}
