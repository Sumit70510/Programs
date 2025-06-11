#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long n;
	    cin>>n;
	    string s,p;
	    cin>>s>>p;
	    n=s.length();
	    int ptr1;
	    bool flag=1;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]!=p[i])
	        {
	            if(p[i]=='1')
	            {flag=0;break;}
	            else
	            {   ptr1=s.find('0');
	                if(ptr1>i&&ptr1<n)
	                {s[i]=p[i]='*';
	                 s[ptr1]='1';      
	                }
	                else
	                {flag=0;break;}
	            }
	        }
	        else
	        { s[i]=p[i]='*';}
	    }
	    if(flag)
	    {cout<<"Yes";}
	    else
	     cout<<"No";
	    cout<<endl; 
	}
	return 0;
}


s