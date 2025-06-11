#include<iostream>
using namespace std;

struct function
{
   int x,y;
   function(int i,int j)
    {x=i;y=j;}
   void print()
    {cout<<x<<" "<<y<<endl;}  
};
int main()
{
    function f1('a','A');
    f1.print();
    return 0;
}
