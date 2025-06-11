#include <iostream>
#include<string.h>
using namespace std;
int T,x,i,j,count,address[10];
char dict[10][1000],str[1000];
int seperatecheck(char arr[],char strcopy[])
{  int temp=0,matchfound,k;
    int c1= strlen(strcopy);
   for(int i=temp,j=0;j<strlen(arr);i++)
   {
       if(arr[j]==strcopy[i])
       {j++;}

           if(i>=c1)
           {
               matchfound=0;
               break;
           }

        if(j>=strlen(arr))
        {
            matchfound=1;
        }
   }
   return matchfound;
}

void detectbydeleting ( )
{
    int flag;
    j=0;
    count=0;
    for(i=0;i<x;i++)
    {
        flag=seperatecheck(dict[i],str);
        if(flag)
        {   count++;
            address[j++]=i;
        }
    }

}

char *comparelongest()
{
    int sizeofaddress[10],big=0,addresstrack;
    for(i=0;i<count;i++)
    {
        sizeofaddress[i]=strlen(dict[address[i]]);
    }
    for(i=0;i<count;i++)
    {
        if(sizeofaddress[i]>big)
        {big=sizeofaddress[i];
            addresstrack=address[i];
        }
    }
    return(dict[addresstrack]);
}

int main()
{  cin>>T;
   while(T--)
   {
       cin>>x;
       for(i=0;i<x;i++)
       {
        cin>>dict[i];
       }
       cin>>str;
       detectbydeleting();

       cout<<"\n"<<comparelongest();
   }
    cin>>T;
	return 0;
}
