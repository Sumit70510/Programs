#include <bits/stdc++.h>
using namespace std;
void print(vector<int>arr,int n)
{ cout<<n<<endl;
  int k=0;
  while(n--)
   {cout<<arr[k]<<" "<<arr[k+1]<<endl;
    k+=2;
   }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
	  vector<int> arr(n+1),lastbit(n+1,0),position(n+1,0),ans,ans0;
	  int op1=0,op0=0;
	  int ones=0,zeros=0,fact=0;
	  for(int i=1;i<=n;i++)
	   {cin>>arr[i];
	     if((arr[i]&1)!=0) 
	      {lastbit[i]=1;
	       position[ones]=i;
	       ones++;   
	      }
	     else
	      {zeros++;}
	   }
	  if(zeros!=n)
	   { if(zeros==0)
	      { for(int i=1;i<=n;i++)
	         { if(i%2==0)
	            {op0++;
	             ans.push_back(i);
                 ans.push_back(i-1);
	            }
	         }
	       print(ans,op0);
	       continue;
	      }///tested
	     else
	      { 
	        ////////////// 1 at 1 3 5///////////////
	        ////////////// 0 at 2 4 6///////////////
	        for(int i=1;i<=n;i++)
	         {if(i%2==1)
	           { if(lastbit[i]==0)
	              {op1++;
	               ans.push_back(i);
	               if(i==1)
	                {ans.push_back(position[0]);}
	               else
	                {ans.push_back(i-2);}
	              }
	           }
	          else
	           { if(lastbit[i]==1)
	              {op1++;
	               ans.push_back(i);
	               if(i==2)
	                {ans.push_back(1);}
	               else
	                {ans.push_back(i-1);}  
	              }
	           }
	         }///tested
	    ////////////////////////////////////////////
	   //////////////////1 at 2 4 6////////////////
	   //////////////////0 at 1 3 5//////////////// 
	       for(int i=1;i<=n;i++)
	         {if(i%2==0)
	           { if(lastbit[i]==0)
	              {op0++;
	               ans0.push_back(i);
	               if(i==2)
	                { ans0.push_back(position[0]); }
	               else
	                { ans0.push_back(i-2);}
	              }
	           }
	          else
	           { if(lastbit[i]==1)
	              {op0++;
	               ans0.push_back(i);
	               if(i==1)
	                { if(i==position[0]&&ones==1)
	                   {op0=INT_MAX;break;}
	                  else
	                   { if(i==position[0])
                          {ans0.push_back(position[1]);}
                         else 
                          {ans0.push_back(position[0]);} 
                       }   
	                }
	               else
	                {ans0.push_back(i-1);}   
	              }
	           }
	         }
	    ////////////////////////////////////////// 
	      }
	   }
	  else
	   {cout<<(-1)<<endl;continue;}
	  if(op0<=op1)
	   {print(ans0,op0);}
	  else
	   {print(ans,op1);}
	}
	return 0;
}