#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	long long int x,y,multiply=1,strength=0;
	while(t--)
	{ cin>>x>>y;
	  int n =x/y;
	  int arr[9];
	  int i=0;
	  multiply=y;
	    while(i<n&&i<9)
	    {   arr[i]=(multiply*(i+1))%10;
	        strength+=arr[i];
	        i++;
	    }
	    if(i<n)
	   {
	       if(n/10>0)
	       {strength*=(n/10);}
	       if(n%10>0)
	       {   i=0;
	           while(i<(n%10))
	           {strength+=arr[i];i++;}
	       }
	   }
	   cout<<strength<<endl;
	}
	cin>>t;
	return 0;
}

