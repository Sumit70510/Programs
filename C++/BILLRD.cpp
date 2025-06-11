#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, n, k, x, y, bx[4], by[4];
    cin >> t;
    while (t--)
    {   
        cin >> n >> k >> x >> y;
        if (x == y)
        {   x = n;
            y = n;
        }
        else
        {   int i=0,j=3,tem,add[4],ct=k%4 ;
            bx[0]=max(x-y,y-x);  bx[1]=n;
            bx[2]=n-bx[0];       bx[3]=0;
            
            while(i<4)
            {add[i]=i;by[j--]=bx[i++];}
            if(y>x)
            { for(i=0,j=3;i<2;i++,j--)
               {tem=add[i];
                add[i]=add[j];
                add[j]=tem;
               }
            } 
            x = bx[add[ct]];
            y = by[add[ct]];
        }
        cout << x << " " << y << endl;
    }
    return 0;
}