#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
	  vector<int> arr(n),lastbit(n,0),position_1,position_0,ans;
	  int operations=0;
	  int ones=0,zeros=0;
	  for(int i=0;i<n;i++)
	   {cin>>arr[i];
	     if((arr[i]&1)!=0) 
	      {lastbit[i]=1;ones++;
	       position_1.push_back(i);   
	      }
	     else
	      {zeros++;
	       position_0.push_back(i);   
	      }
	   }
	   int alterfactor=0; 
	  if(zeros!=n)
	   { if(zeros==0)
	      { for(int i=0;i<n-1;i+=2)
	         { if(i%2==0)
	            {operations++;
	             ans.push_back(i);
	             ans.push_back(i+1);
	            }
	         } 
	      }
	     else
	      { if(zeros==ones)
	         {cout<<0<<endl;continue;}
	        else
	         { int odd0=0,odd1=0,even0=0,even1=0;
	           int even_major,odd_major,major,index,even_winner,odd_winner;
	           int minor;
	           for(int i=0;i<n;i++)
	            { if(i%2==0)
	               { if(lastbit[i]==0)
	                  {even0++;}
	                 else
	                  {even1++;}
	               }
	              else
	               { if(lastbit[i]==0)
	                  {odd0++;}
	                 else
	                  {odd1++;}
	               }
	            }
	           even_major=((even1>even0)?1:0);
	           even_winner=max(even0,even1);
	           odd_major=((odd1>odd0)?1:0); 
	           odd_winner=max(odd0,odd1);
	           index=((odd_winner>even_winner)?1:0);
	           if(index==0)
	            {major=even_major;
	             minor=((even_major==1)?0:1);         
	            }
	           else
	            {major=odd_major;
	             minor=((odd_major==1)?0:1);     
	            }
//////////////////////XOR WITH ONE//////////////////////////
	           for(int i=0;i<n-1;i++)
	            { if(i%2==0)
	               { if(index==(i%2))
	                  { 
	                    if(lastbit[i]==minor)
	                     {operations++;
	                      ans.push_back(i+1);
	                      if(i<2)
	                       {  int k=0;
	                             if(position_1[k]!=i)
	                             {ans.push_back(position_1[k]+1);}
	                            else
	                             {ans.push_back(position_1[k+1]+1);}
	                       }
	                      else
	                       {
	                         if(minor==1)
	                          {  ans.push_back((2/(minor+index))); }
	                         else
	                          {ans.push_back(1+index);}
	                       }
	                     }
	                  }
	                else
	                 { if(lastbit[i]==major)
	                    { operations++;
	                      ans.push_back(i);
	                      if(i<2)
	                       {  int k=0;
	                          if(position_1[k]!=i)
	                           {ans.push_back(position_1[k]+1);}
	                          else
	                           {ans.push_back(position_1[k+1]+1);}
	                       }
	                         else
	                          {
	                           if(minor==1)
	                            {ans.push_back((2/(minor+index))); }
	                           else
	                            {ans.push_back(1+index);}
	                          }   
	                       }
	                      else
	                       {
	                           
	                       }
	                    }
	                 }
	               }
	              else
	               {
	                   
	               }
	            }
/////////////////////////////////////////////////////////////            
	         }
	      }
	   }
	  else
	   {cout<<(-1)<<endl;continue;}
	 cout<<operations<<endl;
	 for(auto i:ans)
	  {cout<<i<<" ";}
	 cout<<endl; 
	}
	return 0;
}

