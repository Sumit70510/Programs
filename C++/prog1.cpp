#include<iostream>
using namespace std;
short int i,j,mat[9][9];

int repetition(int submat[9])
{   int count;
    for(i=0;i<9;i++)
    {   count=0;
        for(j=0;j<9;j++)
        {
            if(submat[j]==(i+1))
            {
                count++;
            }
        }
        if(count>1)
         return 1;
    }
     return 0;
}

int calculate()
{
    int copy[9],flag=0,next=0,tempi=0,tempj=0,reverse=0;;
     for(i=0;i<9;i++)
     { for(j=0;j<9;j++)
       {  if(!reverse)
        copy[j]=mat[j][i];
        else
        copy[j]=mat[j][i];
       }
      flag=repetition(copy);
      if(flag)
      { return 0;}
       if((i==8)&&!reverse)
       {reverse=1;}
    }
    for(int k=0;k<3;k++)
    {
        for(i=tempi;i<tempi+3;i++)
        {
          for(j=tempj;j<tempj+3;j++)
           {
               copy[next++]=mat[i][j];
           }
           tempj+=3;
           flag=repetition(copy);
           if(flag)
           { return 0;}
        }
        tempi+=3;
        next=0;
    }
    return 1;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {

    for(i=0;i<9;i++)
     for(j=0;j<9;j++)
      cin>>mat[i][j];
    cout<<calculate();
  }cin>>i;
	return 0;
}
