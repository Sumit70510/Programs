#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,count=0;
	    cin>>n;
	    string b;
	    cin>>b;
	    for(int i=0;i<n;i++)
	    {  if(b[i]=='1')
	         {count++;}
	    }
	    if((120-n)+count>=90)
	    {cout<<"YES"<<endl;}
	    else
	    {cout<<"NO"<<endl;}
	}
	return 0;
}
