#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	long n,m,temp;
	while(t--)
	{ 
	    cin>>n>>m;
		vector <pair<long,long>> a;
	    vector <long>b;  
		for(long i=0;i<n;i++)
	     {cin>>temp;
	       switch(temp)
	       {
	         case 1 : a.push_back(make_pair(temp,i+1)); 
					   break;
  	         case 2 : a.push_back(make_pair(temp,i+1));  
           }
	     }
	    for(long i=0;i<m;i++)
	     { cin>>temp;b.push_back(temp);}
		long tempr;
		 for(long j=0;j<b.size();j++)
		 {   long i=b[j];
		     tempr=-1; 
			 temp=-1;
			 if(i>=a.size()){i=a.size()-1;}
		     while(i>=0)
		     { if(a[i].second==1)
				{ tempr=a[i].second;
				  break;}
			   i--;
			 }i=b[j];if(i>=a.size()){i=0;}
			 while(i<a.size())
			  {if(a[i].first==2)
				{ temp=a[i].second;break;}
               i++;
			  } long answer=-1;
		    if(temp=-1&&tempr!=-1)
			{cout<<'h';
			 answer=min(b[j]-tempr,temp-b[j]);	
			}else
			 { if(temp==-1&&tempr!=-1)
			    {answer=b[j]-tempr;}
			   else
			    {if(tempr==-1&&temp!=-1)
			      {answer=b[j]-temp;}		 			
y				}
			 }
		  cout<<answer<<" ";
		 }  
        cout<<endl;
	  }
	return 0;
}e


	        