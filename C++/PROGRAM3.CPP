#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void EightWaySymmetricPlot(int xc,int yc,float x, float Y)
{
putpixel(x+xc,Y+yc,RED);
 putpixel(x+xc,-Y+yc,YELLOW);
  putpixel(-x+xc,-Y+yc,GREEN);
   putpixel(-x+xc,Y+yc,YELLOW);
    putpixel(Y+xc,x+yc,BROWN);
    putpixel(Y+xc,-x+yc,GREEN);
    putpixel(-Y+xc,-x+yc,BLUE);
}
void BresenhamCircle(int xc,int yc, int r)
{
float x=0,y=0,q=0,qm=4.5;
 float i=0.0001;
 while(q<qm)
  {  x=r*cos(q);
     y=r*sin(q);
      EightWaySymmetricPlot(xc,yc,x,y);
      q+=i;
  }
}
int main()
{
int xc,yc,r,errorcode;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
errorcode = graphresult();
if(errorcode!= grOk)
{cout<<"Graphics error:"<<grapherrormsg(errorcode);
 cout<<("Press any key to halt");
 getch();
  exit(0);
}
/*cout<<"Enter the value of xc and yc : ";
 cin>>xc>>yc;
  cout<<"Enter the value of radius : ";
  cin>>r;
   */
   xc=300;
   yc=300;
   r=100;
   BresenhamCircle(xc,yc,r);
    getch();
    closegraph();
     return 0;
}
