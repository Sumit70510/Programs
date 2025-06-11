#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ int len,oper=0,temp,loc=1,loc2=0;
	  float percent1=0,percent2=0,percent_vowel=0,percent_consonent=0,maxi=0,maxoccur=0,nv=0,nc=0;
	  vector<int>psbl(26,0);
	  char alpha='a';
	  cin>>len;  
	  string s,p;
	  cin>>s>>p;
	  for(int i=0;i<len;i++)
	   {
	     if(s[i]=='?'&&p[i]!='?')
	      {
	        if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u')
	         {nv++;psbl[p[i]-'a']++;}
	        else
	         {nc++;psbl[p[i]-'a']++;} 
	      }
	     if(p[i]=='?'&&s[i]!='?')
	      {
	        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
	         {nv++;psbl[s[i]-'a']++;}
	        else
	         {nc++;psbl[s[i]-'a']++;}    
	      }
	   }
	   
	       float temp_consonent_per=0,temp_vowel_per=0;
	       percent_consonent= float(nc/float(nc+nv));
	       percent_vowel=float(nv/float(nc+nv));
	       //////////////consonents/////////////
	       alpha='b';
	       maxi=psbl[1];
	       for(int i=2;i<26;i++)
	        { if(i!=4||i!=8||i!=14||i!=20)
	           { temp=psbl[i];
	             if(temp>maxi)
	              {maxi=temp;
	               loc=i;      
	              }
	           }
	        }   
	        if(nc>0)
	        { percent1=float((nc-maxi)/(float)nc); } 
	       //////////we must compare vowels 
	       maxoccur=psbl[0];
	       for(int i=1;i<26;i++)
	        { if(i==4||i==8||i==14||i==20)
	           { temp=psbl[i];
	             if(temp>maxoccur)
	              { maxoccur=temp;
	                loc2=i;
	              }
	           } 
	        }
	       if(nv>0) 
	        {percent2=float((nv-maxoccur)/(float)nv);} 
	       //////////////////////////////////
	      temp_consonent_per= percent1*percent_consonent*100;
	      temp_vowel_per=percent2*percent_vowel*100;
	  	  percent_vowel*=100;
	  	  percent_consonent*=100;
	  	  //////////////////////////////////
	  	  if((temp_vowel_per*2+percent_consonent)<(percent_vowel+temp_consonent_per*2))
	  	   { alpha='a'+ loc2;}
	  	  if((temp_vowel_per*2+percent_consonent)>(percent_vowel+temp_consonent_per*2))
	  	   {alpha='a'+loc;}
	  	     
       for(int i=0;i<len;i++)
	   {
	       if(s[i]=='?')
	        {s[i]=alpha;}
	       if(p[i]=='?')
	        {p[i]=alpha;}
	   }
	   
	  for(int i=0;i<len;i++)
	   {
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
	   
	  cout<<oper<<endl; 
	}
	return 0;
}

