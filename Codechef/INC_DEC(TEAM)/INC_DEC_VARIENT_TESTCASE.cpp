
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//#define fo(i,n) for(i=0;i<n;i++)
ll i,n;
ll solve(int arr){
    ll n=1;
    /*cin >> n;
    ll arr[n];
    for(i=0 ; i< n;i++){
        cin >> arr[i];
    }*/
    ll oper =0 ;
    while(1){
        for(i =0 ; i < n;i++){
            if(arr%2 == 1 ){
                oper++;
                ll dum = arr;
                ll x = (dum >> 1) & 1;
                if(x == 0 || arr == 3){
                    arr--;
                }else{
                    arr++;
                }
            }
        }
        ll check = 0;
        for(i =0 ; i < n;i++){
            arr = arr/2;
            if(arr!= 0)check = -1;
        }
        if(check == 0){
            break;
        }
        oper++;
    }return oper;
}

bool ispowerof2(int n)
 {return (n&&!(n&(n-1)));}
int countbit(int n)
 { int bits=0;
   while(n>>=1)
   {bits++;}
   return bits; } 
void judge(int element,int &sumfactor,int &multiplyfactor)
{
   int n,ans=0,ans2=0,sum=0,sum2=0;
   n=element;
  if(n>1) 
   {/////////nearest power of 2
   int bit=countbit(element);
   ans=((abs((1<<bit)-n)<=abs((1<<bit+1)-n))?bit:bit+1);
   sum=abs((1<<ans)-n);
   sum++;
   while(n)
    { if(n%2==0)
       { if(ispowerof2(n))
         { ans2+=countbit(n);
           n=0;break;
         }
         else 
          {ans2++; n/=2;}      
       }
      else 
       {sum2++;n--;}       
     }
     sum2++;
   if(sum+ans<=(sum2+ans2))
    {multiplyfactor=ans;
     sumfactor=sum;
     element-=sum+1;
    }
   else
    {multiplyfactor=ans2; 
     sumfactor=sum2;
     element-=sum2+1;
    }
   }
   else
    { sumfactor=1;
      multiplyfactor=0;    
    }
}
int solve2(int arr)
 {
     int answer=0,n=1;
      int factor=0,factorsum=0,maxfactor=0;
	  /*for(int i=0;i<n;i++)
	   { cin>>arr;}*/
	  for(int i=0;i<n;i++)
	   { if(arr!=0)
	      {judge(arr,factorsum,factor);
	       maxfactor=max(maxfactor,factor);
	       answer+=factorsum;
	      }    
	   }
	   answer+=maxfactor; 
	   return answer;
 }
 long long int total,wrong,pass;
void result(long long v,int count,int i)
 {    total++;pass++;
     if(count!=v)
      {wrong++;
       cout<<"OBTAINED ANSWER : "<<count<<endl;
       cout<<"CORRECT  ANSWER : "<<v<<endl;
       cout<<"FOR TEST CASE N = "<<i<<endl;
       cout<<endl;  
      }
      if(pass==1000)
       {cout<<"\n PROCESSING......."<<endl;
        pass=0;
       }
 }
int main() {
	int t;
    total=0;
    wrong=0;
    pass=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{ 
      result(solve(i),solve2(i),i);
    }
    cout<<endl;
    cout<<"TOTAL NO. OF TEST CASES : "<<total<<endl;
    cout<<"WRONG TEST CASES : "<<wrong<<endl;
	return 0;
}