#include <iostream>
#include<string.h>
using namespace std;
int main()
{  int T,x,i,address=-1;
   cin>>T;
   while(T--)
   { cin>>x;
     char dict[x][1000],str[1000];
     for(i=0;i<x;i++)
       cin>>dict[i];
     cin>>str;
     int k,l,j=0,big=0,lenofdict,lenofstr=strlen(str);
     for(i=0;i<x;i++)
      {  lenofdict=strlen(dict[i]);
         for(k=0,l=0;l<lenofdict;k++)
           {  if(dict[i][l]==str[k])
               {  if(++l>=lenofdict)
                   {  if(big<lenofdict)
                       {big=lenofdict;  address=i;}
                   }  
               }
              else
                if(k>=lenofstr||lenofstr<lenofdict||(k-l)>=(lenofstr-lenofdict))
                  break; 
          }  
      } if(address>-1){cout<<dict[address];}  else{cout<<"NOTHING MATCHED";}
   } return 0;
}
