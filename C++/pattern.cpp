#include<bits/stdc++.h>
using namespace std;
int dc(int a)
{
   int l=0;
   while(a)
   {a/=10;l++;}
   return l;
}

void space(int a)
 {
   while(a--)
    {cout<<" ";}
 }

int main()
{
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    int t=dc(n);

    for(int i=0;i<n;i++)
     {
        for(int j=0;j<2*n;j++)
         {
            /*for numbers of first half like 12345*/
            if( n-j-i > 0 )
             { cout<<j+1;
               space(t-dc(j+1));
             }

            /* this is for "*" inside first half */
            if( (n-j-i) <=0 && j<n)
             {
               cout<<"*";
               space(t-1);
             }
            // if(j==n)
            //  {space(1);}
            /* this is for "*" in second half */
            if(j >= n && (n-(j-i)>0) )
             {
               if(j==n)
               {
                 space(t-1);
                 cout<<"*";
                }
               else
               {space(t-1);
                cout<<"*";}
             }

            /*for numbers of second half like 54321*/
            if( j >= (n+i) )
             {
               space(t-dc(2*n-j));
               cout<<2*n-j;
             }
             space(1);
         }
         cout<<endl;
     }
  cin>>n;   
  return 0;
}
