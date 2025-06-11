/* C++ program to calculate addition of two different units in single unit */ 
#include<iostream> 
using namespace std; 
class DB;
class DM
{
public: 
float meter,centi; 
//public: 
void getdata() 
{
cout<<"\nEnter the distance in (meter-centimeter):"; 
cin>>meter; 
cin>>centi;
}
void display() 
{
cout<<"\nThe distance is:"; 
cout<<meter<<"mtr and"<<centi<<"centimeter"; 
} 
friend void add(DM &, DB &);
}; 
class DB 
{ 
public: 
float inch, feet; 
//public: 
void getdata()
{
cout<<"\nEnter the distance in (feet-inch):"; 
cin>>feet>>inch; 
}
void display()
{
cout<<"\nThe distance is:"; 
cout<<feet<<"Ft. and "<<inch<<"inch";
}
friend void add(DM&, DB&); 
};
void add(DM &a, DB &b) 
{
int ch; 
cout<<"\nPress 1 for meter-centimeter"; 
cout<<"\nPress 2 for feet-inches"; 
cout<<"\nEnter your choice:"; 
cin>>ch; 
int c=(a.meter* 100+b.feet*30.48+b.inch*2.54); 
if(ch==1) 
{
  DM d; 
if(c>=100) 
{d.meter=c/100; 
d.centi=c%100; 
}
else
{
d.meter=0; 
d.centi=c; 
}
d.display(); }
else 
{
DB d; 
int i=(a.meter*39.37+a.centi*0.3937008+b.feet*12+b.inch); 
if(i>=12) 
{
d.feet=i/12; 
d.inch=i%12; 
}
else 
{
d.feet=0; 
d.inch=i;
}
d.display(); 
}
}
int main() 
{
DM a; 
DB b; 
a.getdata(); 
b.getdata(); 
add(a,b); 
return(0); 
}
