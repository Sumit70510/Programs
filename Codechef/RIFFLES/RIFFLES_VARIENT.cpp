#include <bits/stdc++.h>
using namespace std;
int powerof2(int n)
{return (n&&!(n&(n-1)));}
int main() {
	int t,t2=0;
	//cin>>t;t2=t*2+1;
    int n=2,count=0;
   // vector<int> samecount(t2,0);
	while(n<300000+1)
	{ long long int k;
	  vector<int> arr(n+1,0);
	  vector<int> copy(n+1);
	  vector<int> testarr(n+1,0);
	  for(int i=1;i<=n;i++)
	   {arr[i]=i;}
	   copy=testarr=arr;
	  /* k=k%rep_factor;
	      int reverse=0;
	   if(rep_factor/2<k)
	    {reverse=1;
	     k=rep_factor-k;
	    }*/
      if(powerof2(n))
      {
       if(n>2) 
	    {int first=1,element_first=0,rest=0;
         do{
	        for(int i=2,j=3;i<=n/2;i++,j+=2)
	         { copy[i]=arr[j];  
                if(first==1)
                {element_first++;}
                  rest++;
             }
	        for(int i= n/2 + 1,j=2;i<n;i++,j+=2)
	         { copy[i]=arr[j];
               if(first==1)
                {element_first++;}
               rest++; 
             }first=0;
            if(element_first==rest)
             {cout<<"ELEMENT INTERCHANGED : "<<element_first<<endl;}
            else
             {cout<<" ! ELEMENTS ARE NOT SAME : "<<element_first<<" , "<<rest<<endl;}
            rest=0;      
            count++;   
		    arr=copy;
            }while(arr!=testarr);
         }  
	   count++;
     
          cout<<" RATIO = "<<n<<" : "<<count;
          cout<<"  (POWER OF 2 )"<<endl;
      }
     /*else 
      {cout<<endl;} 
	 */
     n<<=1;
    }
    /*
    cout<<"DATA ANALYSATION :-\n";
    for(int i=1;i<t2;i++)
      {cout<<i<<" : "<<samecount[i]<<" ; ";}
     */
    cout<<"count is : "<<count<<endl;
  return 0;
}
