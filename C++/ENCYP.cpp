#include <bits/stdc++.h>
using namespace std;
int main()
  {
	int t;
	cin>>t;
	while(t--)
	{   int key[]={98,57,31,45,46},no[5];
	    string s;
	    cin>>s;
	    for(int i=0;s[i]!='\0';i++)
	    {
	        s[i]-='A';
	        s[i]+=key[i];
	        s[i]%=26;
	        s[i]+='A';
	    }
	    cout<<s<<endl;
	}cin>>t;
	return 0;
}
