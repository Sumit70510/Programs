#include<bits/stdc++.h>
using namespace std;


int main()
{ 
  
  for(int i=0;i<8;i++)
   {
     for(int j=0;j<8;j++)
      {
        if(i==0||i==7||j==0||j==7)
         {  xk=i;yk=j;
           for(int ii=0;ii<8;ii++)
            { 
                for(jj=0;jj<8;jj++)
                 {
                   if(ii!=i||jj!=j)
                    {  x1=ii;y1=jj;
                      for(int fi=0;fi<8;fi++)
                        {
                         for(int fj=0;fj<8;fj++)
                          {
                            if((fi!=i||fj!=j)&&(fi!=ii||fj!=jj))
                             {
                               r1=coordinate1(i,j,ii,jj,fi,fj);   
                               r2=coordinate2(i,j,ii,jj,fi,fj);   
                               compare(r1,r2);
                             }
                          } 
                        }
                    }
                 }
           }
         }
      }
   }  
    return 0;
}
