#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{   int n,i;
	    cin>>n;
	    int c[n];
	    for(i=0;i<n;i++)
	     cin>>c[i];
	     sort(c,c+n,greater<int>());
	     for(i=0;i<n;i++)
	     cout<<c[i]<<" ";
	     cout<<endl;
	     int sum=0,s1=0,s2=0;
	    if(n%2==0)
	     {   for(i=0;i<=n-2;i++)
	         {
	           s1=max(c[i],c[i+1]);
	           s2=min(c[i],c[i+1]);
	           i++;
	          if(s2<0)
                sum+=s1-s2;
              else
	          sum+=s1;
	            if((s1+s2)&&(i<n-2))
	           { c[i+1]+=s2-s1;
                }
	         }
	      }
	     else
	     {     for(i=0;i<n-1;i++)
	        {
	          s1=max(c[i],c[i+1]);
	          s2=min(c[i],c[i+1]);
               i++;
	          if(s2<0)
                sum+=s1+s2;
              else
	          sum+=s1;
	          c[i+1]+=s2-s1;
	        }`
	       sum+=c[i];
	     }
	     for(i=1;i<n;i++)
	      s1+=c[i];
	     if(c[0]>s1)
	     cout<<c[0]<<endl;
	     else
	     cout<<sum<<endl;
	}cin>>t;
	return 0;
}
