#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
int gd,gm,x,y,end_,p,x2,y2,dx,dy;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
cout<<"Enter the co-ordinate of first point (x,y) : ";
int xx,yy,W;
cin>>xx>>yy;
cout<<"Enter the co-ordinate of second point (x,y) : ";
cin>>x2>>y2;
dx=abs(xx-x2);
dy=abs(yy-y2);
p=2*dy-dx;
if(xx>x2)
{x=x2; y=y2; end_=xx;}
else
{x=xx; y=yy; end_=x2;}

putpixel(x,y,W);

while(x<=end_)
{
    if(p<0)
     {x++;
      p=p+2*dy;
     }
   else
  {
    x++;y++;
    p=p+2*(dy-dx);
  }
putpixel(x,y,W);
}

getch();
 closegraph();
  return 0;
}
