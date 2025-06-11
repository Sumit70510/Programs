#include<bits/stdc++.h>
using namespace std;
int main()
{//////////count no. of bits
 int n;
 cin>>n;
 int count=0;
 while(n)
  {count++;
   n>>=1;}
 cout<<count<<endl;
return 0;
}