#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{  
	  int d,x,y,z,maxwork=0;
	  cin>>d>>x>>y>>z;
	  maxwork=max((x*7),y*d+(z*(7-d)));
	  cout<<maxwork<<endl;
	}
	return 0;
}


