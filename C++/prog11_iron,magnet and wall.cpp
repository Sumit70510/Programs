#include<bits/stdc++.h>
using namespace std;
int sij,i,j,k,n,n_x=0,n_m=0,n_i=0,pos_x[105],target_i[100],target_m[100],targated_i_n=0,final_ans=0,lf=0,inct_in_x=0,temp=0;
string s;
#define pij_() k+1-max(j-i,i-j)-sij

int targetlock(int a)
 {  i=a;
    bool fail=0;
    targated_i_n=0;
    for(int g=lf;g<n_m;g++)
     {    sij=0;j=target_m[g];
          for(int i=min(a,target_m[g]);i<max(a,target_m[g]);i++)
            { switch(s[i])
               { case ':' :sij++; break;
                 case 'X' :fail=1;temp=i;i=max(a,target_m[g]);
               }
            }
            if(!fail)
             {if(pij_()>0)
              targated_i_n++;
             }
             else
             {fail=0;
               if(g>temp&&a>temp)
                lf=g;
               if(a<temp)
                break;
             }
    }
     return targated_i_n;
 }
int main()
{
  int t;
  cin>>t;
   while(t--)
   {
       cin>>n>>k;
       string discrip="IM_:X";
       cin>>s;
       for(i=0;i<n;i++)
       {   switch(s[i])
           {case 'X':pos_x[n_x++]=i;break;
            case 'M':target_m[n_m++]=i;break;
            case 'I':target_i[n_i++]=i;
           }
       }
       for(int i=0;i<n_i;i++)
       {
          if(targetlock(target_i[i])==1)
            {final_ans++;}
       }
       cout<<final_ans<<endl;
   }
  cin>>t;
 return 0;
}
