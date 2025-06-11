#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
	  int num[n];
	  long long int ans=0;
	  switch(n)
	   {
	    case 3 : ans=10; break;
	    case 5 : ans=270;break;
	    case 4 :  
	          for(num[0]=0;num[0]<3;num[0]++)
	           {for(num[1]=0;num[1]<3;num[1]++)
	               {for(num[2]=0;num[2]<3;num[2]++)
	                 {	
                        for(int i=1;i<n-1;i++)        
                         { if((num[i]>num[i-1]&&num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
                              {ans++;}
                         }               
	                 }
	               }
	             }
           break;
  	   case 6: 
  	          
  	         for(num[0]=0;num[0]<3;num[0]++)
	           {for(num[1]=0;num[1]<3;num[1]++)
	              {for(num[2]=0;num[2]<3;num[2]++)
	                 {for(num[3]=0;num[3]<3;num[3]++)
	                   {for(num[4]=0;num[4]<3;num[4]++)
	                     {for(num[5]=0;num[5]<3;num[5]++)
  	                       {  for(int i=1;i<n-1;i++)        
                               { if((num[i]>num[i-1]&&num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
                                   {ans++;}
                                }                                  
                           }
	                     }
	                   }
	                 }
	              }
	            }  
  	       break;
  	       
  	   case 7:
  	         	         
  	         for(num[0]=0;num[0]<3;num[0]++)
	           {for(num[1]=0;num[1]<3;num[1]++)
	              {for(num[2]=0;num[2]<3;num[2]++)
	                 {for(num[3]=0;num[3]<3;num[3]++)
	                   {for(num[4]=0;num[4]<3;num[4]++)
	                     {for(num[5]=0;num[5]<3;num[5]++)
  	                       {for(num[6]=0;num[6]<3;num[6]++)
  	                         {      for(int i=1;i<n-1;i++)        
                                      { if((num[i]>num[i-1]&&num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
                                        {ans++;}
                                      }                               
                             }   
                           }
	                     }
	                   }
	                 }
	              }
	            }
	           break;
	        
  	   case 8:
  	       
  	         for(num[0]=0;num[0]<3;num[0]++)
	           {for(num[1]=0;num[1]<3;num[1]++)
	              {for(num[2]=0;num[2]<3;num[2]++)
	                 {for(num[3]=0;num[3]<3;num[3]++)
	                   {for(num[4]=0;num[4]<3;num[4]++)
	                     {for(num[5]=0;num[5]<3;num[5]++)
  	                       {for(num[6]=0;num[6]<3;num[6]++)
  	                         {for(num[7]=0;num[7]<3;num[7]++)
  	                           {
                                     for(int i=1;i<n-1;i++)        
                                      { if((num[i]>num[i-1]&&num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
                                        {ans++;}
                                      }                               
                                
                               }
                             }   
                           }
	                     }
	                   }
	                 }
	              }
	            }
	           break;
	         
  	   case 9:
  	       
  	         for(num[0]=0;num[0]<3;num[0]++)
	           {for(num[1]=0;num[1]<3;num[1]++)
	              {for(num[2]=0;num[2]<3;num[2]++)
	                 {for(num[3]=0;num[3]<3;num[3]++)
	                   {for(num[4]=0;num[4]<3;num[4]++)
	                     {for(num[5]=0;num[5]<3;num[5]++)
  	                       {for(num[6]=0;num[6]<3;num[6]++)
  	                         {for(num[7]=0;num[7]<3;num[7]++)
  	                           {for(num[8]=0;num[8]<3;num[8]++)
  	                             {
                                     for(int i=1;i<n-1;i++)        
                                      { if((num[i]>num[i-1]&&num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
                                        {ans++;}
                                      }                               
                                 }
                               }
                             }   
                           }
	                     }
	                   }
	                 }
	              }
	            }
	           break;        
	        
  	   case 10:
  	       
  	         for(num[0]=0;num[0]<3;num[0]++)
	           {for(num[1]=0;num[1]<3;num[1]++)
	              {for(num[2]=0;num[2]<3;num[2]++)
	                 {for(num[3]=0;num[3]<3;num[3]++)
	                   {for(num[4]=0;num[4]<3;num[4]++)
	                     {for(num[5]=0;num[5]<3;num[5]++)
  	                       {for(num[6]=0;num[6]<3;num[6]++)
	                         {for(num[7]=0;num[7]<3;num[7]++)
	                           {for(num[8]=0;num[8]<3;num[8]++)
	                             {for(num[9]=0;num[9]<3;num[9]++)
	                               { 
                                     for(int i=1;i<n-1;i++)        
                                      { if((num[i]>num[i-1]&&num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
                                        {ans++;}
                                      }     
                                   }
	                   }
	                 }
	              }
	            }
  	                       }
	                     }
	                   }
	                 }
	              }
	            
	           break; 
	     }
	       
	  cout<<ans<<endl;
	}
	return 0;
}

