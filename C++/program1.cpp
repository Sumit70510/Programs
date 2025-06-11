#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
int main()
{int input;
int x,y,x1,y1,x2,y2,p,dx,dy;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");
cout<<"\nEnter the x-coordinates of the first point : ";
cin>>x1;
cout<<"\nEnter the y-coordinates of the first point : ";
cin>>y1;
cout<<"\nEnter the x-coordinates of the second point : ";
cin>>x2;
cout<<"\nEnter the y-coordinates of the second point : ";
cin>>y2;
x=x1; y=y1;
dx=x2-x1;
dy=y2-y1;
putpixel(x,y,2);
p=((2*dy)-dx);
while(x<=x2)
{
 if(p<2){
 x=x+1;
 p=2*x-dx;
 }
 else{
 x=x+1;
 y=y+1;
 p=p+2*dy;
 }
 putpixel(x,y,7);
}
getch();
closegraph() ;
return 0;
}
