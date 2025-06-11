#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
template <typename t,typename b>
void print(t x,b y)
 { 
    for(int i : x)
     { cout<<i<<" "<<y<<" ";}
    cout<<endl; 
 }
int main()
{
   string str="S";
    vector<int> v;
    for(int i=1;i<=10;i++)
     {v.push_back(i);}
    print<vector<int>,string>(v,str);
    print<vector<int>,int>(v,0);
    print(v,11.1);
     return 0;
} 