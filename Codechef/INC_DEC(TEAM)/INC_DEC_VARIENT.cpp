#include<bits/stdc++.h>
using namespace std;
bool ispowerof2(int n)
 {
   return (n&& !(n&(n-1)));     
 }
 int countbit(int n)
  {
     int bits=0;
     while(n>0)
     {bits++;n>>=1;}
     bits--;
     return bits;  
  }
int main()
{
   int t,t2,sum=0;
   cin>>t;
   t2=t;
  while(t--)
  {  
  int n,ans=0,ans2=0,difference=0,temp;
    cin>>n;temp=n;
   if(ispowerof2(n))
    { ans=countbit(n);}
   else
    { while(n!=0)
       { n++; 
         ans++;
        if(ispowerof2(n))
         { ans+=countbit(n);
           n=0;
         }
       }
     } n=temp;
    while(n!=0)
     { if(n%2==0)
        { if(ispowerof2(n))
          { ans2+=countbit(n);
            ans2++;n=0;break;
          }
          else 
           {  ans2++;
              n/=2; 
           }      
        }
      else 
        { ans2++;
          n--;   
        }       
     }
   //*/ 
  cout<<ans<<" : "<<ans2 <<endl;
  cout<<"DIFFERENCE : "<<ans2-ans<<endl;
    sum+=abs(ans-ans2);
   }

  cout<<"GRAND AVERAGE : "<<sum/t2<<endl;
  return 0;
}