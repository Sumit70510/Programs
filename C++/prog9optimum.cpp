 #include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{   int n,i,sum=0,burner1=0,burner2=0;
	    bool flag=0;
	    cin>>n;
	    int c[n];
	    for(i=0;i<n;i++)
	     cin>>c[i];
	     sort(c,c+n,greater<int>());
	     if(n%2==0)
	      flag=1;
	       for(i=0;i<n-1;i++)
	        {
	          burner1=max(c[i],c[i+1]);
	          burner2=min(c[i],c[i+1]); i++;
	          if(burner2<0)
	          { sum+=max(burner2*(-1),burner1)+burner2;
	            burner1*=-1;}
	          else
               sum+=burner1;
	          switch(flag)
	           {
	             case 0 :    c[i+1]+=burner2-burner1; break;
	             case 1 :    if(i<n-2)
	                           c[i+1]+=burner2-burner1;
	           }
	        }
	       if(!flag&&c[i]>0)
	        sum+=c[i];
	       cout<<sum<<endl;
	} cin>>t;
	return 0;
}
