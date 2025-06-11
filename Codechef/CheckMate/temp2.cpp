#include <iostream>
 
using namespace std;
class Box;
class Ball {
   double width;
   
   public:
      friend void printWidth( Box box,Ball b );
      void setWidth( double wid );
}; 
class Box {
   double width;
   
   public:
      friend void printWidth( Box box ,Ball b);
      void setWidth( double wid );
};

// Member function definition
void Box::setWidth( double wid ) {
   width = wid;
}
void Ball::setWidth( double wid ) {
   width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth( Box box, Ball b ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box 1 : " << box.width <<endl;
   cout << "Width of box 2 : " << b.width <<endl;
}
 
// Main function for the program
int main() {
   Box box;
   Ball b;
   // set box width without member function
   box.setWidth(10.0);
   b.setWidth(15.0);
   
   // Use friend function to print the wdith.
   printWidth( box,b );
 
   return 0;
}