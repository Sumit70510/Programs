#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n;
	cin>>n;
	int flag=1;
	signed long long int c[n];
	for(long long int i=0;i<n;i++)
    {cin>>c[i]; }
    long long int currsum=0,maxsum=0,init=0,sum=0,track=0,du_maxsum=0;
    for(long long int i=0;i<n;i++)
    {  currsum=0;
       for(long long int j=i;j<n;j++)
       {  currsum+=c[j];
          if(currsum>=maxsum)
          {track=j;}
          if(currsum<maxsum&&i>track)
          {init=max(init,maxsum); }  
          maxsum=max(currsum,maxsum);
       }
    }
    sum=maxsum+init;
    cout<<sum<<endl;
	return 0;
}


