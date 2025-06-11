#include<bits/stdc++.h>
using namespace std;
int main()
{   long a,b;
    cin>>a>>b;
    int temp;
    fstream testcase;
    testcase.open("testcase.txt",ios::out);
    testcase<<a<<" "<<b<<endl;
    for(long i=0;i<a;i++)
    {
      if(i%3==0)
      { temp=(rand()%3);
        testcase<<temp<<" ";
        cout<<temp<<" ";
       }
      else
       { if(i%7==0)
        {temp=(rand()%3);
         testcase<<temp<<" ";
         cout<<temp<<" ";}
       else
        {temp=(rand()%3);
         testcase<<temp<<" ";
         cout<<temp<<" ";
        }}
    }
    testcase<<'\n';
    cout<<endl;
    for(long i=0;i<b;i++)
    {   temp=(rand()%a)+1;
        testcase<<temp<<" ";
        cout<<temp<<" ";
    }
    cin>>a;
    return 0;
}
