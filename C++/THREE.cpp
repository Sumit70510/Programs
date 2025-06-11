#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n=s.length(),coin=0,k;
	    sort(s.begin(),s.end());
	    int count=0,temp=0;
		for(int i=0;i<n;i++)
	    {    if(i<n-1)
		       { if(s[i]!=s[i+1])
	             {temp++;}
	             else
	             {count++;i++;}
			   }
			  else
			  { temp++;  }
	    }
	    k=count*2+temp;
	    for(int i=0;i<n;)
	    {
	       if(i<(count*2)&&k-i>=3)
	       {   i+=2;k--;
	           coin++;
	       }
	       else
	       break;
	    }
	    cout<<coin<<endl;
	}
	return 0;
}
