#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{  
	   int n,m,l;/////////
	   cin>>n>>m>>l;///////
	   int k,temp,s[l],id[n+1];
	   for(int i=0;i<m;i++)
	   {  cin>>k;
	      for(int j=0;j<k;j++)    
	      {cin>>temp;
	       id[temp]=k;
	      }
	   }
       for(int i=1;i<=n;i++)
       {cout<<id[i]<<" ";}
	   /*
	   for(int i=0;i<l;i++)
	   {cin>>s[i];}
	   int segment=1,i=0;
       while (i<l-1)
       { cout<<"run i : "<<i<<endl;
         if(id[s[i]]==id[s[i+1]])
         {i++; }
         else
         {segment++;}
         i++;
       } 
	   cout<<segment<<endl;*/
    }  
	return 0;
}


