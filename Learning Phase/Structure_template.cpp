#include<iostream>
using namespace std;
template<typename T>
struct Function
{ T x,y;
  Function(T i,T j){x=i;y=j;}
  T get_x(){return x;}
  T get_y(){return y;}
  T outside();
};
template <typename T>
T Function<T>::outside()
{return x;}
int main()
{
   Function<int>f1(10,20);
   cout<<f1.get_x()<<endl;
   cout<<f1.get_y()<<endl;
   cout<<f1.outside();
   return 0; 
}