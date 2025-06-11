#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ int len,oper=0,maxi=10e6;
	  char alpha='a';
	  cin>>len;  
	  string s,p;
	  cin>>s>>p;
	  string s_temp=s,p_temp=p;
	
	 for(int i=0;i<26;i++)
	  { s=s_temp;p=p_temp;
	    for(int i=0;i<len;i++)
	    {
	       if(s[i]=='?')
	        {s[i]=alpha;}
	       if(p[i]=='?')
	        {p[i]=alpha;}
	       
	     if(s[i]!=p[i])     
	      {
	        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
	         {
	           if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u')
	            {oper+=2;}
	           else
	            {oper++;}
	         }
	        else
	         {
	           if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u')
	            {oper++;}
	           else
	            {oper+=2;}
	         }
	      }  
	   }
	   maxi=min(oper,maxi);
	   oper=0;
	   alpha++;
	  } 
	  cout<<maxi<<endl; 
	}
	return 0;
}

