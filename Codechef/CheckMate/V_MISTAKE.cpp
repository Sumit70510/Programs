#include <bits/stdc++.h>
using namespace std;

#define loop(x) for(x=0;x<3;x++)
#define revloop(x) for(x=2;x>=0;x--)

//----------------------------------------CLASS FOR POSITION OF ELEMENTS-------------------------------------------------
class Elements
{ public :
    int x,y;
  void getdat()
   {cin>>x>>y;}
  void construct(Elements &A)
   {x=A.x;y=A.y;}
} King,Rook1,Rook2;
//---------------------------------------------END OF ELEMENTS-----------------------------------------------------------

//--------------------------------------CORDINATE MANAGEMENT SYSTEM------(CONTAINER)-------------------------------------
class CMS
{   public:
    int Container[3][3],update;
    CMS()
     {  int i,j; update=0;loop(i){loop(j){Container[i][j]=-2;}} }
    CMS(CMS &A)
     { int i,j;  update=0;loop(i){loop(j){Container[i][j]=A.Container[i][j];}}  }
//======================================================================================================================
    void Coustom_constructor()
     {  int i,j; update=0;loop(i){loop(j){Container[i][j]=-2;}} }
//======================================================================================================================
// friend void zone_boundary(Merge_CMS,CMS);
//======================================================================================================================
    int instant_count()
     {   int count=0,i,j;
         loop(i)
           {loop(j)
             { if(Container[i][j]==1){count++;} }
           }
        return count;
     }
//======================================================================================================================
int count_report(int k,int zone);
//======================================================================================================================

/*==============================PRINTING FOR DEVELOPER=================================================================
void print()
{
  int i,j;
  revloop(i)
   { loop(j)
      {cout<<Container[i][j]<<" ";}
      cout<<"\n";
   }
  cout<<"NO OF POSSIBLE LIVES : ";
  cout<<instant_count()<<"\n";
}
//=============================================DEVELOPER=================================================================*/
}live;
//--------------------------------------------END OF CMS-----------------------------------------------------------------

//------------------------------------MERGE COORDINATE MANAGEMENT SYSTEM-------------------------------------------------
 class Merge_CMS
  { public :
    CMS x,y;
    void Reset()
     {x.Coustom_constructor();
      y.Coustom_constructor();}
   // friend void zone_boundary(Merge_CMS,CMS);
  }Zone;
//-------------------------------------------END OF MERGE_CMS------------------------------------------------------------

//-------------------------------------------CLASS FOR VIRTUAL MOVES-----------------------------------------------------
class Moves
{ public:
  Elements Virtual_rook1[2],Virtual_rook2[2];
//======================================================================================================================
  void Moves_initalize()
    {  for(int i=0;i<2;i++)
       {Virtual_rook1[i].construct(Rook1);
        Virtual_rook2[i].construct(Rook2);} }
//======================================================================================================================

//======================================================================================================================
void find_Movement()
{
     if(Rook1.x==Rook2.x)
      {
        Virtual_rook1[0].x=King.x;
        Virtual_rook2[0].x=King.x;
      }
     else
      {
        if(Rook1.y!=Rook2.y)
         {
           Virtual_rook1[0].x=King.x;
           Virtual_rook2[0].x=King.x;
         }
        else
         {
            if(Rook1.x<Rook2.x)
             { if(King.x>Rook2.x)
                {Virtual_rook1[0].x=-1;
                 Virtual_rook2[0].x=King.x;}
               else
                {
                 if(King.x<Rook1.x)
                  {Virtual_rook2[0].x=-1;
                   Virtual_rook1[0].x=King.x;}
                 else
                  { Virtual_rook2[0].x=King.x;
                    Virtual_rook1[0].x=King.x;
                  }
                }
             }
            else
             {
              if(King.x>Rook1.x)
               {Virtual_rook2[0].x=-1;
                Virtual_rook1[0].x=King.x;}
              else
               { if(King.x<Rook2.x)
                  { Virtual_rook2[0].x=King.x;
                    Virtual_rook1[0].x=-1;
                  }
                 else
                  { Virtual_rook2[0].x=King.x;
                    Virtual_rook1[0].x=King.x;
                  }
               }
             }
           }
      }
 //************************************************************************************************************************
    if(Rook1.y==Rook2.y)
     {
       Virtual_rook1[1].y=King.y;
       Virtual_rook2[1].y=King.y;
     }
    else
     {
       if(Rook1.x!=Rook2.x)
        {
          Virtual_rook1[1].y=King.y;
          Virtual_rook2[1].y=King.y;
        }
       else
        {
          if(Rook1.y<Rook2.y)
           {
            if(King.y>Rook2.y)
             {Virtual_rook1[1].y=-1;
              Virtual_rook2[1].y=King.y;}
            else
             { if(King.y<Rook1.y)
                {Virtual_rook2[1].y=-1;
                 Virtual_rook1[1].y=King.y;
                }
               else
                { Virtual_rook1[1].y=King.y;
                  Virtual_rook2[1].y=King.y;
                }
             }
           }
          else
           {
             if(King.y>Rook1.y)
              {Virtual_rook2[1].y=-1;
               Virtual_rook1[1].y=King.y;}
             else
              { if(King.y<Rook2.y)
                 { Virtual_rook1[1].y=-1;
                   Virtual_rook2[1].y=King.y;
                 }
                else
                 { Virtual_rook2[1].y=King.y;
                   Virtual_rook1[1].y=King.y; }
              }
           }
        }
     }
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
}
//======================================================================================================================

} V_Moves;
//----------------------------------------------END OF MOVES-------------------------------------------------------------

//----------------------------------------FUNCTION OF CMS CLASS----------------------------------------------------------
int CMS::count_report(int k,int zone)
 {
  int i,j;
/////////////////////////Ist move////////// x1 /////&&/////y1///////////////////////////////////////////////
if(zone==1)
 {
     loop(i)
      {loop(j)
          {  if(i!=1||j!=1)
              {
if(Zone.x.Container[i][j]==V_Moves.Virtual_rook1[k].x&&Zone.y.Container[i][j]==V_Moves.Virtual_rook1[k].y||(Zone.x.Container[i][j]==Rook2.x&&Zone.y.Container[i][j]==Rook2.y))
                 {
if(V_Moves.Virtual_rook1[k].x!=Rook2.x&&V_Moves.Virtual_rook1[k].y!=Rook2.y)//////////////means no backup///////////////////////////
                      {continue;}
                    else
                      {Container[i][j]=-2;update++;}
                 }
                else
                {
if(Zone.x.Container[i][j]==V_Moves.Virtual_rook1[k].x||Zone.x.Container[i][j]==Rook2.x||Zone.y.Container[i][j]==V_Moves.Virtual_rook1[k].y||Zone.y.Container[i][j]==Rook2.y)
                   {Container[i][j]=-2;update++;}
                 }
              }
          }
       }
     if(V_Moves.Virtual_rook1[k].x==-1||V_Moves.Virtual_rook1[k].y==-1)
       {return -1;}
}
//////////////////////////////3rd move///x2 & y2/////////////////////////////////////////////
else
  {
    if(zone==2)
     {
       loop(i)
       {loop(j)
           {  if(i!=1||j!=1)
               {
if(Zone.x.Container[i][j]==V_Moves.Virtual_rook2[k].x&&Zone.y.Container[i][j]==V_Moves.Virtual_rook2[k].y||(Zone.x.Container[i][j]==Rook1.x&&Zone.y.Container[i][j]==Rook1.y))
                  {
if(V_Moves.Virtual_rook2[k].x!=Rook1.x&&V_Moves.Virtual_rook2[k].y!=Rook1.y)//////////////means no backup///////////////////////////
                       {continue;}
                     else
                       {Container[i][j]=-2;update++;}
                  }
                 else
                 {
if(Zone.x.Container[i][j]==V_Moves.Virtual_rook2[k].x||Zone.x.Container[i][j]==Rook1.x||Zone.y.Container[i][j]==V_Moves.Virtual_rook2[k].y||Zone.y.Container[i][j]==Rook1.y)
                    {Container[i][j]=-2;update++;}
                  }
               }
           }
        }
//////mistake FOUND///////////////
    if(V_Moves.Virtual_rook1[k].x==-1||V_Moves.Virtual_rook1[k].y==-1)
       {return -1;}
     }
   }

  return( instant_count() );
}
//----------------------------------------CMS CLASS FUNCTION ENDS---------------------------------------------------------

//-------------------------------------COUNTING MANAGEMENT SYSTEM CLASS--------------------------------------------------
class COMS
{ int Possible_lives[4],check_update;
  public:
  void COMSS()
   {for(int i=0;i<4;i++){Possible_lives[i]=-1;}
    check_update=0;
   }
//==================================ACTION FUNCTION FOR IMPLEMENTING ACTIONS=============================================
  int Action()
   {for(int i=0;i<4;i++)
     { CMS clone(live);
         if(i<=1)
          {Possible_lives[i]=clone.count_report(i,1);
           check_update=max(check_update,clone.update);}
         else
           {Possible_lives[i]=clone.count_report(i-2,2);
            check_update=max(check_update,clone.update);}
     }
//**********************FINDING PERMOTED COUNT************************
    return(permote());
   }
//===========================================END OF ACTION===============================================================

//===================================FINDING THE PERMOTABLE ARRAY========================================================
int permote()
{
 if(check_update==0){return 0;}
 for(int i=0;i<4;i++)
  {  if(Possible_lives[i]==0)
      {return(1);}
  }
  return 0;
}
//========================================END OF PERMOTE FUNCTION========================================================

//==========================================Zone Boundary================================================================
void zone_boundary()
 { int i,j;/////////clear
   revloop(i)
     { loop(j)
        { if((King.x+i-1<=8)&&(King.x+i-1>=1))
           {Zone.x.Container[i][j]=(King.x)-1+i;}
          if((King.y+j-1<=8)&&(King.y+j-1>=1))
           {Zone.y.Container[i][j]=(King.y)-1+j;}
          if((King.y+j-1<=8)&&(King.y+j-1>=1)&&((King.x+i-1<=8)&&(King.x+i-1>=1)))
            {live.Container[i][j]=1;
             if(i==1&&j==1){live.Container[i][j]=2;}}
         }
      }
  }
//=======================================END OF ZONE_BOUNDARY============================================================
}take;
//----------------------------------------------END OF COMS--------------------------------------------------------------


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	  int status=0,count=-1;
	  King.getdat();
      Rook1.getdat();
      Rook2.getdat();
      Zone.Reset();
      live.Coustom_constructor();
      take.COMSS();
      take.zone_boundary();
      count=live.instant_count();
      if(count<=5)
	     {
        V_Moves.Moves_initalize();// INITIALIZING VIRTUAL MOVES
        V_Moves.find_Movement();  // FINDING POSSIBLE MOVES
        status=take.Action();     // MAKING REPORT OF POSSIBLE MOVES
       }
      else
       {status=0;}

    if(status>=1)
     {cout<<"YES\n";}
    else
     {cout<<"NO\n";}

	}
	return 0;
}