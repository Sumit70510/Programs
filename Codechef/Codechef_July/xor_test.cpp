#include<bits/stdc++.h>
using namespace std;
int main()
{  
  int a,b,ans,ans2;
  cin>>a>>b;
  for(int i=1;i<a;i++)
  {   ans=b^i;ans2=i^b;
      cout<<b<<" ^ "<<i<<" :  "<<ans;
      cout<<"\t";
      cout<<i<<" ^ "<<b<<" :  "<<ans2;
      cout<<endl;
   }
  return 0;
}