#include<iostream>
#include<vector>
using namespace std;
template <typename T>
T findmax(T x,T y)
 {
    return ((x>y)?x:y); 
 }

int main()
{
   cout<<findmax<int>(213,23421)<<endl;
   cout<<findmax<char>('%','a')<<endl;
    cout<<findmax<float>(2.343435,3.00244023)<<endl;
    return 0;
}