#include<bits/stdc++.h>
using namespace std;


class animal 
{
  public :
   virtual void properties()=0;   
};

class dog : public animal
 {
    
   public : 
   void properties()
    {
       cout<<"This is a Dog";
    } 
 };

 
 
int main()
 {
   animal *d1 = new dog();
   d1->properties();   
   return 0;
 }