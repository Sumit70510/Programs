#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> list,c={1,2,3};int temp;
    vector <int> ::iterator i;
    for(auto i :c)
     {cout<<i<<" ";}
     cout<<endl;
    for(int i=1;i<=6;i++)
     {list.push_back(i);}
    list.pop_back();
    for(auto i=list.rbegin();i!=list.rend();i++)
     {cout<<*i<<" "; }
     cout<<endl;
     cout<<list.front()<<endl;
     cout<<list.back();
     for(auto  &i:list)
      {i++;}
    i=list.begin();
    cout<<endl;
    cout<<*(next(i,3));
    cout<<endl; 
    cout<<*(next(i,4));
    cout<<endl;
    i+=4; 
    cout<<*(prev(i,4));
    cout<<endl;
    cout<<*i; 
    advance(i,-4);
    cout<<endl;
    cout<<*i<<'\n'; 
    for(int i : list)
     {cout<<i<<" ";}
     
    /////////////////////////////////
    cout<<"\nbits\n";
    int countbit=0,n=7;
    vector <int> bits;
    do
        {countbit++;
         bits.push_back(n|0);        
        }while(n>>=1);
    cout<<countbit<<endl;;
    for(auto i:bits)
     {cout<<i<<" ";}
    return 0;
}