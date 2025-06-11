#include<bits/stdc++.h>
using namespace std;
int turn;
 class INFINITY1
 {
   public:

    int n[1000][1000][100];

    INFINITY1 *next;
    void INFINIT(); 
 };


 void INFINITY1::INFINIT() {
     int z=1000;
     for(int i=0;i<z;i++)
     {
         for(int b=0;i<z;i++)
         {
             for(int c=0;i<z/10;i++)
              {n[i][b][c]=0;}
             
         }
     }
 };

 /*void animation()
 {
   cout<<endl;
    for(int i=turn;i<60+turn;i++)
    {
      if(i%2==0)
      {cout<<0<<" ";}
      else
      {cout<<1<<" ";}
    }
    
    for(long long int  i=0; i<1000;i++)
    for(long long int  j=0; j<10000;j++);
    cout<<endl;
    if(turn==0)
    {turn=1;}
    else
    {turn=0;}
 }*/

 int main()
 {   turn =0;
     INFINITY1 *a,*Head;
      INFINITY1 *temp;
     while(1)
     {  
        temp=new INFINITY1;
        temp->INFINIT();
        temp->next=NULL;
        a=temp;
        cout<<a<<" ";
        a=a->next;
        delete temp;
       // animation();              
     }        
     delete a;
     return 0;
 }
