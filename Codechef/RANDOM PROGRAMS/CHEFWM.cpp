#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	  long long int n,m;
	   cin>>m;
	  vector<long long int> prime (m+1,0) ;
	  long long int count=0;
	  for(long long int i=2;i<=m;i++)
	   {
	     if(prime[i]==0)
	      {
	          for(long long int j=i*i;j<=m;j+=i)
	           {prime[j]=1;}
	      }
	   }
       
	  for(long long i=2;i<m&&count<n;i++)
	   {
	     if(prime[i]==0) 
	      {if(2310%i==0)
           {count++;}
	      }        
	   }
	  cout<<count<<endl;
	  //cout<<count<<endl;
	}
	return 0;
}

