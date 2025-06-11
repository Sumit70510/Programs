#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int temp=n,count=0,bit=0;
  while(n>>=1)
   {count++;}
   cout<<"bits : "<<count<<endl;
  int po2_1=1,po2_2=1;
  po2_1<<=count;
  po2_2<<=count+1;
  bit=temp;
  temp=((abs(po2_2-temp)>=abs(po2_1-temp))?po2_1:po2_2);
  cout<<temp<<endl;
  cout<<"PATH : "<<temp-bit<<endl;
  cout<<(1<<3);
  return 0;
}
