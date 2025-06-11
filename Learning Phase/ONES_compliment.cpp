#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  /////count no of bits
  int countbit=floor(log2(n)+1);
  ///////////////////////////
  int compliment=((1<<countbit)-1)^n;
  cout<<compliment<<endl;
  return 0;  
}