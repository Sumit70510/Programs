#include <bits/stdc++.h>
using namespace std;
#define loop(x,a,n) for(x=a;x<n;x++)

int zonex[3][3],zoney[3][3],live[3][3];
int xk,yk,x1,y2,x2,y1;
int move_live[3][3];
void copy()
{
  for(int i=0;i<3;i++)
   {
     for(int j=0;j<3;j++)
      {live[i][j]=move_live[i][j];}
   }
}
int instant_count(int arr[3][3]);
int *count_report(int arr[],int count)
{ 
  int *count_temp,k=0;  
  int temp_move=arr[k];
  int i,j,a=0;
  count_temp=new int [4];
  copy();
  /////////////////////////Ist move////////// x1 //////////////////////////////////////////////////    
      loop(i,a,3)
       {
         loop(j,a,3)
          {  if(i!=1||j!=1)  
              { 
                if(zonex[i][j]==temp_move&&zoney[i][j]==y1)
                 {
                    if(temp_move!=x2&&y1!=y2)//////////////means no backup///////////////////////////
                      {continue;}
                    else 
                      {move_live[i][j]=-1;}  
                 }
                else 
                {
                  /*if(y1>yk)
                   { if(zoney[i][j]>yk&&zonex[i][j]==temp_move)
                        {count_temp[k]--;}  }
                  else 
                   { if(zoney[i][j]<yk&&zonex[i][j]==temp_move)
                      {count_temp[k]--;} }*/   
                  if(zonex[i][j]==x2||zonex[i][j]==temp_move)////////update//////////
                   {move_live[i][j]=-1;} 
                  if(zoney[i][j]==y1||zoney[i][j]==y2)
                   {move_live[i][j]=-1;}
                 }  
              }                 
          }
       }
     count_temp[k]=instant_count(move_live);  
///////////////////////////tested////////////////////////////////////////////////////////////
///////////////////////////////////2nd move/////y1////////////////////////////////////////////////////
    k++;
    copy();
    temp_move=arr[k];
      loop(i,a,3)
       {
         loop(j,a,3)
          {  if(i!=1||j!=1)  
              { 
                if(zonex[i][j]==x1&&zoney[i][j]==temp_move)
                 {
                    if(temp_move!=y2&&x1!=x2)//////////////means no backup///////////////////////////
                      {continue;}
                    else 
                      {move_live[i][j]=-1;}  
                 }
                else
                 {               
                   /*if(x1<xk)
                    { if(zonex[i][j]<xk&&zoney[i][j]==temp_move)
                       {count_temp[k]--;}  }
                   else 
                    { if(zonex[i][j]>xk&&zoney[i][j]==temp_move)
                       {count_temp[k]--;} }  */  
                   if(zonex[i][j]==x2||zonex[i][j]==x1)
                     {move_live[i][j]=-1;} 
                   if(zoney[i][j]==y2||zoney[i][j]==temp_move)/////////////////update//////////////////
                    {move_live[i][j]=-1;} 
                 }
              }                
           }
       }
      count_temp[k]=instant_count(move_live);
   ///////////////////////////tested/////////////////////////////////////////////////////
 //////////////////////////////3rd move///x2//////////////////////////////////////////////////      
    k++;
  copy();
     int move_live[3][3]=live;/////error
      loop(i,a,3)
       {
         loop(j,a,3)
          {  if(i!=1||j!=1)  
              { 
                if(zonex[i][j]==temp_move&&zoney[i][j]==y2)
                 {
                    if(temp_move!=x1&&y1!=y2)//////////////means no backup///////////////////////////
                      {continue;}
                    else 
                      {move_live[i][j]=-1;}  
                 }
                else
                 { /*if(y1<yk)
                    { if(zoney[i][j]<yk&&zonex[i][j]==temp_move)
                      {count_temp[k]--;}  }
                    else 
                     { if(zoney[i][j]>yk&&zonex[i][j]==temp_move)
                        {count_temp[k]--;} } */  
                    if(zonex[i][j]==x1||zonex[i][j]==temp_move)///////////////UPDATE////////////////////
                     {move_live[i][j]=-1;} 
                    if(zoney[i][j]==y1||zoney[i][j]==y2)
                     {move_live[i][j]=-1;} 
                 }
              }               
          }
       }
    count_temp[k]=instant_count(move_live);
    //////////////////////////////////////////Tested///////////////////////////////////////////////////////
    ////////////////////////////////////fourth move////y2//////////////////////////////////////////////////    
    k++;
    temp_move=arr[k];
    copy();
      loop(i,a,3)
       {
         loop(j,a,3)
          {  if(i!=1||j!=1)  
              {
                if(zonex[i][j]==x2&&zoney[i][j]==temp_move)
                 {
                    if(temp_move!=y1&&x1!=x2)//////////////means no backup///////////////////////////
                      {continue;}
                    else 
                      {move_live[i][j]=-1;}  
                 } 
                else 
                {
                  /*if(x1<xk)
                   { if(zonex[i][j]<xk&&zoney[i][j]==temp_move)
                      {count_temp[k]--;}  }
                     else 
                      { if(zonex[i][j]>xk&&zoney[i][j]==temp_move)
                         {count_temp[k]--;} }  */ 
                     if(zonex[i][j]==x1||zonex[i][j]==x2)
                      {move_live[i][j]=-1;} 
                     if(zoney[i][j]==y1||zoney[i][j]==temp_move)///////////update////////////////////////
                      {move_live[i][j]=-1;} 
                }              
              }              
          }
       }
    count_temp[k]=instant_count(move_live);
    /////////////////////////////////////tested////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
  
    return (count_temp);
}
int instant_count(int live[3][3])
 {
   int count=0;
     for(int i=0;i<3;i++)
       {
          for(int j=0;j<3;j++)
           {
             if(live[i][j]==1)
              {count++;}
           } 
       }
    return count;
 }
int *movement()
  {
     int x1m,x2m,y1m,y2m;
    ///for movement of 1st rook 
    //limitation of x1, if(x2>x1) {x1<x2} if(x1>x2) {x1>x2} 
   if(x1==x2)
    {
      x1m=xk;
      x2m=xk;
    }   
   else 
    {if(y2!=y1)
      {x1m=xk;
       x2m=xk;      
      }
     else
      { 
         if(x1<x2)
          { if(xk>x2)
             {x1m=-1;
              x2m=xk;}
            else
            { if(xk<x1)
               {x2m=-1;
                x1m=xk;}
              else
               {x2m=xk;
                 x1m=xk;
                } 
            }    
          }
         else
          {
            if(xk>x1)
             {x2m=-1;
              x1m=xk;}
            else
             { if(xk<x2)
                { x2m=xk;
                  x1m=-1;}
               else
                { x2m=xk;
                  x1m=xk;
                } 
             }
          }
        }
    } 
     ////////////////////////////////////////////////////
   if(y1==y2)
     {
        y1m=yk;
        y2m=yk;
     }
    else 
     {if(x2!=x1)
      { y1m=yk;
        y2m=yk; }
     else
      { 
        if(y1<y2)
         { if(yk>y2)
            {y1m=-1;
             y2m=yk;}
           else
            { if(yk<y1)
               {y2m=-1;
                y1m=yk;
               }
              else
               { y1m=yk;
                 y2m=yk;
               }     
            }    
          }
        else
         {
           if(yk>y1)
            {y2m=-1;
             y1m=yk;}
           else
            { if(yk<y2)
               { y1m=-1;
                 y2m=yk;  
               }
              else
               { y2m=yk;
                 y1m=yk; }
            }
         }
      }
     } 
     ////////////////////////////////////////////////////
     int arr[]={x1m,y1m,x2m,y2m},*ret;
     ret=new int [4];
     ret=arr;
     return ret;
  }        
int zone_boundary()
 {   int count;
     for(int i=2;i>=0;i--)
      { for(int j=0;j<3;j++)
         {  
            if((xk-1+i)>=1&&(xk+i-1)<=8)
             { zonex[i][j]=xk-1+i;}
            if((yk-1+j)>=1&&(yk-1+j)<=8)
             { zoney[i][j]=yk-1+j;} 
             if((xk-1+i)>=1&&(xk-1+i)<=8||(yk-1+j)>=1&&(yk-1+j)<=8)
              {if(i==j){live[i][j]=2;}
                else{live[i][j]=1;}
              }

         }
      }
    count=instant_count(live);
        
    return count;
  } 
 int kill(int arr[],int count) 
  {   int temp_move,tempy,detect_kill[4]={0,0,0,0};
      int *report,status=0;
      report = new int [4];
      report=count_report(arr,count); 
      for(int i=0;i<4;i++)
      {if(report[i]==0)
         {status=1;break;}
       }
     return status; 
  }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{ 
	  int status;

	 cin>>xk>>yk>>x1>>y1>>x2>>y2;
	 for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
         {
           if(i!=1&&j!=1)
            {
              zonex[i][j]=-1;live[i][j]=-1;zoney[i][j]=-1;
            }
            else
             {live[i][j]=2;}
         }
      }
	 int *arr;
	  arr=new int [4];
    int initial=0,count;
    count=zone_boundary();
    arr=movement();
	    if(count<=5)
        {status=kill(arr,count);}
        else 
       {status=0;}
     
     
      delete arr;
      
      if(status)
       {cout<<"YES\n";}
      else 
       {cout<<"NO\n";}   
      
	}
	return 0;
}