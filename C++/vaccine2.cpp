 #include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,d,day=0,r=0,nr=0;
	    cin>>n>>d;
	    int arr;  
	    for(long long i=0;i<n;i++)
	    {  cin>>arr;
            if(arr>=80||arr<=9)
	         { r++;}
	       else
	        {nr++;}
	    }
        day+=r/d;
        day+=nr/d;
        if(nr%d>0)
         day++;
	    if(n%d>0)
         day++;
        cout<<day<<endl;
	}
	return 0;
}


