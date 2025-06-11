#include<bits/stdc++.h>
using namespace std;
int main()
{ int a,b;
  cin>>a>>b;
  while(b!=0)
   { int common=a&b;
     a^=b;//sum without common
     b=common<<1;//shifting common ones to add next time
   }
  cout<<"SUM OF NUMBERS IS : "<<a<<endl; 
  return 0;  
}