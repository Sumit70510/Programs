 #include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ long long temp,count=0,num=0,init=0;
      bool flag=0;
       string a,b;
	  cin>>a;
	  cin>>b;
	  long long l;
	  for(l=0;a[l]!='\0';l++);
	  for(long long i=0;i<l;i++)
	  {   if(a[i]!=b[i])
	        {  num=2;if(i+1<l)
	                 {temp=i+1;}
	                 else
	                  temp=i;
	           for(long long j=i+1;j<=temp;j++,num++)
	            {  if(num%2==0)
	                 {   if(a[j]==b[j])
	                       {if((++temp)>(l-1))
	                          temp--;
	                       }
	                       else
                           {  flag=1;init=j;
                              if(j+1<l)
                              { if(a[j+1]!=b[j+1])
	                             {
	                               if((++temp)>(l-1))
	                                temp--;
	                             }
	                             else
	                              i=j-1;
                              }      
	                          else 
	                           i=j-1;
	                       }
	                 }
                    else
	                 {
	                   if(a[j]!=b[j])
	                    {   if(flag)
	                        {flag=0;i=init;}
	                        if((++temp)>(l-1))
	                          temp--;
	                    }           
	                   else
	                    if(flag)
	                    {flag=0;i=init;}
	                    else
	                     {i=j;}
	                 }
	           }count++;
	        }   
	  }
	  cout<<count<<endl;
	}
	return 0;
}
