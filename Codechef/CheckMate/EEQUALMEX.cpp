#include <bits/stdc++.h>
using namespace std;
int MEX(set<int> s)
{
    int check=0; 
	for(auto i :s)
	 {if(check==i)
	   {check++;}
	  else
	   {break;}
	 }
    return check;    
}
int COUNT_MEX(vector<int> s,int n)
{
    vector<int> count(n+1,0);
	for(auto i :s)
	 {count[i]++;}
	for(auto i:count) 
     { if((i==1))
        {return 0;} 
     }
     
     
    
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
	  std::vector<int> arr(2*n) ;
	  set<int> s1,s2;
	  for(int i=0;i<n;i++)
	   {cin>>arr[i];
	    s1.insert(arr[i]);}
	  for(int i=n;i<2*n;i++)
	   { cin>>arr[i];
	     s2.insert(arr[i]);
	   }
	  if(MEX(s1)==MEX(s2))
	   {cout<<"YES"<<endl;
	     continue; }
	  if(COUNT_MEX(arr,n))
	   {cout<<"YES"<<endl;}
	  else
	   {cout<<"NO"<<endl;}
	}
	return 0;
}