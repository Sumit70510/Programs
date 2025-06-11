#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    long long n=1;
    while(n<100000000)
     {   
         cout<<n;
         long long  sum=0;
         n--;
         if(n>3)
          {
            long long k=n;
            while(k%3!=0)
             {k--;}
            long long last=k; 
            k-=3;
            k/=3;
            k++;
            if(k>1)
             sum+=(k*(3+last))/2;
            else
             sum+=3;     
          } 
        //   cout<<sum<<endl;
         if(n>5)
          {
            long long k=n;
            while(k%5!=0)
             {k--;}
            long long last=k; 
            k-=5;
            k/=5;
            k++;
            if(k>1)
             sum+=(k*(5+last))/2;
            else
             sum+=5;     
          } 
        //   cout<<sum<<endl;
         if(n>15)
          {
            long long k=n;
            while(k%15!=0)
             {k--;}
            int last=k; 
            k-=15;
            k/=15;
            k++;
            if(k>1)
             sum-=(k*(15+last))/2;
            else
             sum-=15;     
          } 
          long long sum2=0;
          for(long long i=0;i<n+1;i++)
           {
             if(i%3==0||i%5==0)
              {sum2+=i;}   
           }
        if(sum!=sum2)
         {cout<<"NOTWORKING FOR :"<<(n+1)<<endl;
          cout<<"Wrong : "<<sum<<endl;
          cout<<"Correct : "<<sum2<<endl;
         }
         n+=2; 
     } 
    cout<<"working for every thing thanks"; 
    return 0;
}
