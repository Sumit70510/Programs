#include <bits/stdc++.h>
using namespace std;

long long int program1(long long int n,long long int m) {
	long long int i,j,count;
	vector<long long int> prime(m+1,0);
	for( i=2;i<=m;i++)
	{    if(prime[i]==0)
	        { for(j=i*i;j<=m;j+=i)
	             { prime[j]=1;}
	        }
	}
	count=0;
	for(i=2;i<=m;i++)
	 {
	    if(prime[i]==0)
	     {
	       if(m%i==0)
	       {count++;}
	     }
	 }
	  if(count>0)
	  { while(n%count!=0)
	   {count--;}
	  }
	return count;
}

long long program2(long long int a,long long int b) {
	// your code goes here
	int x=0;
	    long long t=0,temp=b;
	    for(long long i=2;i*i<=b;i++)
	    {
	        if(!(temp%i))
	        {
	            t++;
	            while(!(temp%i))
	            {
	                temp/=i;
	            }
	        }
	    }
	    if(temp>1)
	        t++;
        vector<long long> arr;
        for(long long i=1;i*i<=a;i++)
        {
            if(!(a%i))
            {
                arr.push_back(i);
                if(i!=(a/i))
                    arr.push_back(a/i);
            }
        }
        long long v=0;
        for(auto x: arr)
        {
            if(x<=t)
                v=x;
	    }
	   
	return v;
}
long long int total,wrong,pass;
void decide(long long int v,long long int count)
 {    total++;pass++;
     if(count!=v)
      {wrong++;
       cout<<"OBTAINED ANSWER : "<<count<<endl;
       cout<<"CORRECT  ANSWER : "<<v<<endl;
       cout<<endl;  
      }
      if(pass==1000)
       {cout<<"\n PROCESSING......."<<endl;
        pass=0;
       }
 }
int main()
 {  total=0;wrong=0;pass=0;
    long long int n=10e9+1,m=10e9+1;
    for(long long int i=10e4;i<n;i++)
     {
         for(long long j=10e4;j<m;j++)
          {
            decide(program2(i,j),program1(i,j));
          }
     }
    cout<<endl;
    cout<<"TOTAL NO. OF TEST CASES : "<<total<<endl;
    cout<<"WRONG TEST CASES : "<<wrong<<endl;

      

}
