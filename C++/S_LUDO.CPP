#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
   float a=10,b=0,tracex,tracey,boxx[72],boxy[72];
   float k=0,j=0,xaxis=638.5,yaxis=400;
   #define x1 xaxis+b
   #define y1 yaxis+a
   #define midy 159.5+a
   #define midx 255.7+b
   #define gx 42.57
   #define gy 26.667
   #define rad 25
   #define maxx 304.7
   #define maxy 214.7
   #define radg 8
   #define tracexx midx +(3*gx)
   #define traceyy midy + (3*gy)
   float ddx=(xaxis+b)/10,ddlx=((ddx*10)/3.5);
   int n[4][4],turn=-1,ww[4][4];
  void zero()
   { for(int i=0;i<4;i++)
     {for(int j=0;j<4;j++)
      {ww[i][j]=0;}}
   n[0][0]=n[0][1]=n[0][2]=n[0][3]=1;
   n[1][0]=n[1][1]=n[1][2]=n[1][3]=14;
   n[2][0]=n[2][1]=n[2][2]=n[2][3]=27;
   n[3][0]=n[3][1]=n[3][2]=n[3][3]=40;
   }
  float x[4]={(ddx)+b,(ddlx)+b,(ddx)+b,(ddlx)+b};
  float y[4]={40+a,40+a,115+a,115+a};
  float z[]={x1-(ddx+b),x1-(ddlx+b),x1-(ddx+b),x1-(ddlx+b)};
  float v[]={traceyy+40,traceyy+40,traceyy+115,traceyy+115} ;
  char ch[]={'a','s','d','w'};
  int zee=0,die1=0,clr1,r;
 void increment(int,int,int&,char c=' ');
 void frame(float f=255.7+b,float d=159.5+a);
 void move(int,int,int,int,char,int e=8);
 void initialposition(int,int,char);
 void goti(int,int,int,int,char);
 void count(int&,int,int);
 int  rule1(int&,int,int);
 void fragment();
 void position();
 void clr(int a);
 void die(int&);
 void command();
 void box(int);
 void boxmid();
 void circl();
 void sign();

void clr(int a){
  setcolor(a);}

void count(int &x,int side,int num){ 
  int g=++ww[side][num],f;
  if(g>!52&&(x>52))
   {f=x-53;x=f;}
  if(ww[side][num]==52)
    {exit(0);}}

void increment(int side,int num,int &number,char ch){
   int g;
   if(ch=='+')
    { ++n[side][num];
      g=n[side][num];}
   else
    {g=n[side][num];}
   count(g,side,num);
   number=g; /*temp whole function*/}
 

int random(int a)
 {
   return 6;
 }/////////temp

void die(int &b){ 
 int g,f;
 g=random(12334);
 for(int i=0;i<=g;i+=f)
  { b=random(6)+1;
    f=random(2183); 
  }}

void goti(int numb,int die,int color,int side,char e){ 
   int number;increment(side,numb,number);
   move(boxx[number],boxy[number],numb,color,e);
   if(!zee)
    { for(int i=0;i<die;i++)
	     { 
        delay(300);
	      move(boxx[number],boxy[number],numb,0,e);
	      delay(300);
	      increment(side,numb,number,'+');
	      move(boxx[number],boxy[number],numb,color,e);
	     }
    }  
   switch(getch())
    {
     case 27: break;
     default : command();
    }}

void command(){
 int b,color,c=0,a,k[4]={0,0,0,0};
 tr:
 if(turn>=3){turn=0;}
 else{turn++;}
 switch(turn)
 {
  case 0:color=2;break;
  case 1:color=3;break;
  case 2:color=4;break;
  case 3:color=14;break;
 }
 di :
 die(b);box(b);
 /* if(!k[turn])
  { k[turn]++;
    a=rule1(b,c,turn);
    switch(a)
    {
     case 1:goto tr;
     default:break;
    }
  }
 else
 {
 //a=rule1(0,0,0);
 }
 */
 cd:
 switch(getch())
 {
  case 'a':c=0;break;
  case 's':c=1;break;
  case 'd':c=2;break;
  case 'w':c=3;break;
  default : goto cd;
 }
   char vv=ch[c];
 initialposition(c,turn,vv);
 goti(c,b,color,turn,vv);
 if(b==6)
  {goto di;} }

void move(int x,int y,int a,int d,char f,int e){ 
  float xw,yw;xw=x;yw=y;
    char ww[2];
    ww[0]=f;ww[1]='\0';
   clr(d);
   outtextxy(xw-(1.5),yw-(1.5),ww);
   circle(x,y,e);}

int main()
{
   //clrscr();
   zero();
   boxmid();
   int gdriver = DETECT, gmode;
   float c=a,d=0;
   initgraph( &gdriver, &gmode, "c:\turboc3\bgi");
   position();
   frame();
   command();
   getch();
 return 0;
}

void boxmid(){
  int q[4],z[4];
  q[1]=q[3]=-1;
  z[0]=z[1]=0;z[2]=-1;
  for(int i=1;i<=52;i++)
   {
    if((i>=1&&i<=5)||(i>=45&&i<=52)) //xcoordinates b/w 4&&44
     {
      if(i>=1&&i<=5||(i==52))
       { q[0]=0;
	       if(i>=1&&i<=5)
	        {z[0]++;}
	       else
	        {z[0]=0;}
       }
      else
       {
	      if(i>=45&&i<=50)
	       {
	        q[0]=2;
	        if(i>45&&i<=50)
	         {z[0]--;}
	       }
	      else
	       {q[0]=1;z[0]=0;}
       }
	    boxx[i]=((midx)+(gx/2)+(q[0]*gx));   ///x coordinate
	    boxy[i]=(y1)-(gy/2)-(z[0]*gy);
     }  //ok//ok
    if(i>=6&&i<=18)           //xcoordinates b/w 5&&17
     {
      if(i==12||i==13)
       {
        q[1]=5;
        if(i==13)
	       {z[1]=2;}
        else
	       {
	        if(i==12)
	         {z[1]=1;}
	       }
       }
      else
       {
        if(i>13&&i<=18)
	       {q[1]--;z[1]=2;}
        else
	       {q[1]++;z[1]=0;}
       }

      boxx[i]=midx-(gx/2)-(gx*q[1]);
      boxy[i]=traceyy-(gy/2)-(z[1]*gy);
     } //ok //ok

    if(i>=19&&i<=31)          //xcoordinates b/w 18&&30
     {
      if(i>=19&&i<=24)
       {q[2]=0;z[2]++;}
      else
       {
        if(i>=26&&i<=31)
	       {q[2]=2;
	        if(i>26&&i<=31)
	         {z[2]--;}
	       }
        else
	       {q[2]=1;}
       }
	    boxx[i]=midx+(gx/2)+(q[2]*gx);
	    boxy[i]=midy-(gy/2)-(z[2]*gy);
     } //ok //ok

    if(i>=32&&i<=44)         //xcoordinates b/w 31 && 43
     {
      if(i==38||i==39)
       {
        q[3]=5;
        if(i==38)
	       {z[3]=1;}
        else{z[3]=2;}
       }
      else
       {
        if(i>39&&i<=44)
	       {q[3]--;z[3]=2;}
        else{q[3]++;z[3]=0;}
       }

      boxx[i]=tracexx+(gx/2)+(gx*q[3]);
      boxy[i]=midy+(gy/2)+(gy*z[3]);
     }  //ok   //ok
   } }

void circl() {
 for(int i=0;i<=3;i++)
  {  clr(2);
  circle(x[i],v[i],rad);//1ST circle        ok
  circle(x[i],v[i],rad+1.5);//1ST circle    ok
  circle(x[i],v[i],rad+3);//1ST circle      ok
  clr(3);
  circle(x[i],y[i],rad);//2ND circle        ok
  circle(x[i],y[i],rad+1.5);//2ND circle    ok
  circle(x[i],y[i],rad+3);//2ND circle      ok
  clr(4);
  circle(z[i],y[i],rad);//3RD circle        ok
  circle(z[i],y[i],rad+1.5);//3RD circle    ok
  circle(z[i],y[i],rad+3);//3RD circle      ok
  clr(14);
  circle(z[i],v[i],rad);//4TH circle        ok
  circle(z[i],v[i],rad+1.5);//4TH circle    ok
  circle(z[i],v[i],rad+3);//4TH circle      ok
  }}

void box(int die)
 {
   float i;
   if(die1!=die)
    {r=die1;}
   clr1=0;
   die1=die;
   if(r)
   {die=r;clr1=15;}
   bc:
   switch(die)
   {case 1: clr(15-clr1);for(i=0;i<=5;i+=0.5)
    {circle(midx+(gx+(gx/2)),y1+((70-a)/2),5-i); } break;
    case 2: clr(15-clr1);
    for( i=0;i<=5;i+=0.5)
    {circle(midx+(gx),y1+((70-a)/2),5-i);
    circle(tracexx-(gx),y1+((70-a)/2),5-i); } break;
    case 3: clr(15-clr1);
    for( i=0;i<=5;i+=0.5)
    {circle(tracexx-(gx/2),y1+((70-a)/3),5-i);
     circle(midx+((3*gx)/2),y1+((70-a)/2),5-i);
     circle(midx+(gx/2),y1+((2*(70-a))/3),5-i); } break;
   case 4: clr(15-clr1);
    for( i=0;i<=5;i+=0.5)
    {circle(midx+(gx),y1+((70-a)/3),5-i);
    circle(midx+(gx),y1+((2*(70-a))/3),5-i);
    circle(tracexx-(gx),y1+((70-a)/3),5-i);
    circle(tracexx-(gx),y1+((2*(70-a))/3),5-i); } break;
   case 5: clr(15-clr1);
    for( i=0;i<=5;i+=0.5)
    {circle(midx+(gx/2),y1+((70-a)/4),5-i);
    circle(midx+(gx/2),y1+((2*(70-a))/3),5-i);
    circle(midx+(gx+(gx/2)),y1+((70-a)/2),5-i);
    circle(tracexx-(gx/2),y1+((70-a)/4),5-i);
    circle(tracexx-(gx/2),y1+((2*(70-a))/3),5-i); } break;
   case 6: clr(15-clr1);
    for( i=0;i<=5;i+=0.5)
    {
      circle(midx+(gx),y1+((70-a)/4),5-i);
      circle(tracexx-(gx),y1+((70-a)/4),5-i);
      circle(midx+(gx),y1+((70-a)/2),5-i);
      circle(tracexx-(gx),y1+((70-a)/2),5-i);
      circle(tracexx-(gx),y1+((70-a)/4),5-i);
      circle(tracexx-(gx),y1+((3*(70-a))/4),5-i);
      circle(midx+(gx),y1+((3*(70-a))/4),5-i);} break;

   } if(clr1==15)
   {r=0;die=die1;clr1=0;goto bc;}

 } //box close

void position(){ 
 char cha[1];
  //   cha[1][2]=cha[1][3]=cha[1][1]=cha[1][0]='/0';
 for(int i=0;i<=3;i++)
  {switch(i)
  {case 0:cha[0]='a';break;
   case 1:cha[0]='s';break;
   case 2:cha[0]='w';break;
   case 3:cha[0]='d';break;
   }
  clr(2);
  outtextxy(x[i]-1,v[i]-1,cha);
  circle(x[i],v[i],radg);//1ST circle        ok
  clr(3);
  outtextxy(x[i]-1,y[i]-1,cha);
  circle(x[i],y[i],radg);//2ND circle        ok
  clr(4);
  outtextxy(z[i]-1,y[i]-1,cha);
  circle(z[i],y[i],radg);//3RD circle        ok
  clr(14);
  outtextxy(z[i]-1,v[i]-1,cha);
  circle(z[i],v[i],radg);//4TH circle        ok
  }}

void frame(float midlx,float midly)//for main lines inside the box
 {
   int i;clr(15);
   rectangle(midx,y1+1,tracexx,y1+(69-a));
   clr(6);
   line(b,a,b,y1);
   line(x1,a,x1,y1);
   line(b,a,x1,a);
   line(b,y1,x1,y1);
   float dumdx=midlx,dumdy=midly;
   for(i=0;i<=3;i++)
   {
   if(i==0||i==3)
    {
     line(b,dumdy,x1,dumdy);//for 2  horizontal lines of side1
     line(dumdx,y1,dumdx,a);//for 2  vertical lines of side2
     dumdy+=gy; dumdx+=gx;
    }
   else
   {
    line(b,dumdy,midlx,dumdy);//for 2 small horizontal lines of side1 ||entry to home
    line(dumdx,a,dumdx,midly);//home lines of side 2
    dumdy+=gy; dumdx+=gx;  }
   }
   dumdx-=gx;
   dumdy-=gy;
   tracey=dumdy;
   tracex=dumdx;
   for(i=0;i<=3;i++)
   {
    line(x1,midly,dumdx,midly); //home lines of side 3
    line(midlx,dumdy,midlx,y1); //home lines of side 4
    midly+=gy;midlx+=gx;
   }
   fragment();
   circl();
 }

void fragment()
  { float x=midx,y=midy,upx[5],upy[5];

    upx[0]=x;  upx[1]=tracey;  upx[2]=tracex; upx[3]=a;upx[4]=b;

    upy[1]=tracey; upy[2]=upy[3]=tracex; upy[4]=y1;

    for(int i=0;i<=6;i++)
    {
     line(upx[4],y,upx[4],upx[1]);// for boxes of side 1
     line(x,upx[3],upx[2],upx[3]);// for boxes of side 2
     line(upy[3],y,upy[3],upy[1]);// for boxes of side 3

     line(upx[0],upy[4],upy[2],upy[4]);//for boxes of side 4

      upx[4]+=gx; //side 1
      upy[4]-=gy;  //side 4
      upy[3]+=gx; //side 3
      upx[3]+=gy; //side 2
    }
     line(x,y,tracex,tracey);
     line(tracex,y,x,tracey);
     line(x+1,y+1,tracex+1,tracey+1);
     line(tracex+1,y+1,x+1,tracey+1);

  }

void initialposition(int numb,int tur,char chf)
 {  int i=numb; char cha[1],f;
  cha[0]=chf;
   if(tur==0)
    {  if(n[0][numb]>=0)
       { clr(0);
	 outtextxy(x[i]-2,v[i]-2,cha);
	 circle(x[i],v[i],radg);//1ST circle        ok
       }
       else
	{ clr(2);
	   outtextxy(x[i]-1,v[i]-1,cha);
	  circle(x[i],v[i],radg);//1ST circle        ok}
	}
     }
    else
     {
       if(tur==1)
	{
	 if(n[1][numb]>=13)
	  { clr(0);
	     outtextxy(x[i]-1,y[i]-1,cha);
	    circle(x[i],y[i],radg);//2ND circle        ok
	  }
	 else
	  { clr(3);
	    outtextxy(x[i]-1,y[i]-1,cha);
	    circle(x[i],y[i],radg);//2ND circle        ok}
	  }
	}

    else
     {
      if(tur==2)
       {
	if(n[2][numb]>=26)
	 { clr(0);
	    outtextxy(z[i]-1,y[i]-1,cha);
	   circle(z[i],y[i],radg);//3rd circle        ok
	 }
	else
	 { clr(4);
	     outtextxy(z[i]-1,y[i]-1,cha);
	   circle(z[i],y[i],radg);//3rd circle        ok}
	 }
       }
    else
     {
      if(tur==3)
       {
	 if(n[3][numb]>=39)
	  { clr(0);
	     outtextxy(z[i]-1,v[i]-1,cha);
	    circle(z[i],v[i],radg);//4th circle        ok
	  }
	 else
	  { clr(14);
	     outtextxy(z[i]-1,v[i]-1,cha);
	    circle(z[i],v[i],radg);//4th circle        ok}
	  }
       }
     }
     }
     }
 }

int rule1(int &b,int c,int turn)
  {
   zee=0;
   if((n[turn][c]==1)||(n[turn][c]==27)||(n[turn][c]==14)||(n[turn][c]==40))
    {
     if(b!=6)
      {return(1);}
     else
      {
       if(b==6)
        {zee=1;}
      }
    }
   return(0);
  }

void sign()
  {
    int x=0,turn=1,y=0;
    for(int i=0;i<=13;i++,turn++)
     { 
      if(turn==1)
       {x=-15;y=-15;}if(turn==2){turn=0;x=15;y=15;}
      clr(15);
      delay(1500);
      line(gx+x+b,y1+(70-a)/3,midx-((3*gx)/2)+x,y1+(70-a)/3);
      line(gx+x+b,y1+(2*(70-a))/3,midx-((3*gx)/2)+x,y1+(2*(70-a))/3);
      line(gx+x+b,y1+(70-a)/3,gx+x,y1+(2*(70-a))/3);
      line(midx-((3*gx)/2)+x,y1+(70-a)/3,midx-((3*gx)/2)+(gx/2)+x,y1+((70-a)/2));
      line(midx-((3*gx)/2)+x,y1+(2*(70-a))/3,midx-((3*gx)/2)+(gx/2)+x,y1+((70-a)/2));
      line(x1-gx+y,y1+(70-a)/3,tracexx+((3*gx)/2)+y,y1+(70-a)/3);       //right
      line(x1-gx+y,y1+(2*(70-a))/3,tracexx+((3*gx)/2)+y,y1+(2*(70-a))/3);
      line(x1-gx+y,y1+(70-a)/3,x1-gx+y,y1+(2*(70-a))/3);
      line(tracexx+((3*gx)/2)+y,y1+(70-a)/3,tracexx+gx+y,y1+((70-a)/2));
      line(tracexx+((3*gx)/2)+y,y1+(2*(70-a))/3,tracexx+gx+y,y1+((70-a)/2));

      clr(0);
      delay(1500);
      line(x1-gx+y,y1+(70-a)/3,tracexx+((3*gx)/2)+y,y1+(70-a)/3);       //right
      line(x1-gx+y,y1+(2*(70-a))/3,tracexx+((3*gx)/2)+y,y1+(2*(70-a))/3);
      line(x1-gx+y,y1+(70-a)/3,x1-gx+y,y1+(2*(70-a))/3);
      line(tracexx+((3*gx)/2)+y,y1+(70-a)/3,tracexx+gx+y,y1+((70-a)/2));
      line(tracexx+((3*gx)/2)+y,y1+(2*(70-a))/3,tracexx+gx+y,y1+((70-a)/2));

      line(gx+x,y1+(70-a)/3,midx-((3*gx)/2)+x,y1+(70-a)/3);
      line(gx+x,y1+(2*(70-a))/3,midx-((3*gx)/2)+x,y1+(2*(70-a))/3);
      line(gx+x,y1+(70-a)/3,gx+x,y1+(2*(70-a))/3);
      line(midx-((3*gx)/2)+x,y1+(70-a)/3,midx-((3*gx)/2)+(gx/2)+x,y1+((70-a)/2));
      line(midx-((3*gx)/2)+x,y1+(2*(70-a))/3,midx-((3*gx)/2)+(gx/2)+x,y1+((70-a)/2));

      if(kbhit()){break;}
     }  
  //  kbhit()==0;
  }