#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
	  vector<int> arr(n),lastbit(n,0),position(n,0),ans,ans0;
	  int op1=0,op0=0;
	  int ones=0,zeros=0;
	  for(int i=0;i<n;i++)
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
	      { for(int i=0;i<n-1;i+=2)
	         { if(i%2==0)
	            {op0++;
	             ans.push_back(i+1);
	             ans.push_back(i+2);
	            }
	         }
	       cout<<op0<<endl;
	       for(auto i:ans)
	        {cout<<i<<" ";}
	       cout<<endl;
	       continue;
	      }
	     else
	      { 
	        ////////////// 1 at 1 3 5///////////////
	        ////////////// 0 at 0 2 4///////////////
	        for(int i=0;i<n-1;i++)
	         {if(i%2==1)
	           { if(lastbit[i]==0)
	              {op1++;
	               ans.push_back(i+1);
	               if(i<2)
	                { if(i!=position[0])
	                   { ans.push_back(position[0]+1); }
	                  else
	                   {ans.push_back(position[1]+1);}
	                }
	               else
	                {ans.push_back(2);}
	              }
	           }
	          else
	           { if(lastbit[i]==1)
	              {op1++;
	               ans.push_back(i+1);
	               if(i<2)
	                { if(i==position[0]&&ones==1)
	                   { op1=INT_MAX;break;}
	                  else
	                   {
	                     if(i==position[0])
	                      {ans.push_back(position[1]+1);}
	                     else
	                      {ans.push_back(position[0]+1);}
	                   }
	                }
	               else
	                {ans.push_back(2);}  
	              }
	           }
	         }
	    ////////////////////////////////////////////
	   //////////////////1 at 0 2 4////////////////
	   //////////////////0 at 1 3 5//////////////// 
	    for(int i=0;i<n-1;i++)
	         {if(i%2==0)
	           { if(lastbit[i]==0)
	              {op0++;//cout<<"THIS : "<<i+1<<endl;
	               ans0.push_back(i+1);
	               if(i<2)
	                { if(i!=position[0])
	                   { ans0.push_back(position[0]+1); }
	                  else
	                   {ans0.push_back(position[1]+1);}
	                }
	               else
	                {ans0.push_back(1);}
	              }
	           }
	          else
	           { if(lastbit[i]==1)
	              {op0++;
	               ans0.push_back(i+1);
	               if(i<2)
	                { if(i==position[0]&&ones==1)
	                   { ans0.push_back(1); }
	                  else
	                   { if(i==position[0])
	                      {ans0.push_back(position[1]+1);}
	                     else
	                      {ans0.push_back(position[0]+1);}
	                   }  
	                }
	               else
	                {ans0.push_back(1);}   
	              }
	           }
	         }
	    ////////////////////////////////////////// 
	      }
	   }
	  else
	   {cout<<(-1)<<endl;continue;}
	 if(op0<op1)
	  { if(op0!=0)
	     {cout<<op0<<endl;
	      for(auto i:ans0)
	      {cout<<i<<" ";}
	     }
	    else
	     {cout<<0;}
	  }
	 else
	  { if(op0==op1)
	     { if(ans0[n-2]!=ans0[n-1])
	        { cout<<op0<<endl;
	          for(auto i: ans0)
	           {cout<<i<<" ";}
	        }
	       else
	        { if(ans[n-2]!=ans[n-1])
	           { cout<<op1<<endl;
	             for(auto i: ans)
	              {cout<<i<<" ";}
	           }
	          else
	           {cout<<(-1);}
	        }
	     }
	    else
	     { if(op1!=0)
	       {cout<<op1<<endl;
	        for(auto i:ans)
	         {cout<<i<<" ";}
	       }
	       else
	        {cout<<0;}
	     } 
	  }
	 cout<<endl; 
	}
	return 0;
}

