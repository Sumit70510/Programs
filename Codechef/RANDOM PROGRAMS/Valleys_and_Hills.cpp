#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	  int n,m,i,size,edit;
	  int init,jump,check;
	  int post=0;
	  char base,asign;
	  cin>>n>>m;
	  
	  if(n==m)
	   {size=n*2+2;check=0;
	    base='0';jump=2;
	    init=1;edit=-1;
	    post=1;asign='1'; }
	  else
	   {
	     if(n>m)
	      { size=3*n-m;
	        base='0';
	        init=1;
	        asign='1';  
	        post=0; 
	        jump=2;
	        check=1;
	        edit=3*m-(3*n);
	      }
	     else
	      {
	        if(n<m)
	        {
	          size=3*m-n;  
	          base='1';
	          init=1;
	          asign='0';  
	          post=0; 
	          jump=2;
	          check=1;
	          edit=3*n-(3*m);
	        }
	      }
	   }
	   
	  
	  string str(size,base);
      
      loop:
      for(i=init;i<=size+edit;i+=jump)
       { str[i]=asign; }
	  
	  if(check)
	   {init=2*min(m,n)+1;
	    jump=3;
	    check=0;
	    edit=0;
	    goto loop;
	   }
	  if(post)
	   {str[i]=asign;}
	  
	  cout<<size<<endl;
	  cout<<str<<endl;
	}
	return 0;
}

