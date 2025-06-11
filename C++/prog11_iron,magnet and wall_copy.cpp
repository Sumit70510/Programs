#include<bits/stdc++.h>
using namespace std;
int sij,i,j,k,n,M[1000][1000],I[1000][1000],n_i=0,n_m=0;
int lf2=0,n_sub,n_subT[10000];;
string s,sub[10000];
#define pij_() k+1-max(j-i,i-j)-sij
/*bool check(int a)
{

}
void findsij()
{   int f=0;
    for(int i=lf2;target_cs[i]<max(::i,::j);i++)
    {if(target_cs[i]>min(::i,::j))
       {
         sij++;
       }
    }
}
int targetlock(int a)
 {  i=a;
    bool fail=0;
    targated_i_n=0;
    for(int g=lf;g<n_m;g++)
     {   if(check(g))
          {    sij=0;
               j=target_m[g];
               findsij();
               if(!fail)
               { if(pij_()>0)
                 targated_i_n++;
               }
               else
               { lf=g;fail=0;
                 if(a>!temp)
                break;
               }
           }
    }
     return targated_i_n;
 }
/*/
int main()
{
  int t;
  cin>>t;
   while(t--)
   {
       cin>>n>>k;
       cin>>s;
       for(i=0;i<n;i++)
       {   switch(s[i])
           {case 'X':  if(i>1)
                        {  if(s[i-1]!='X')
                            {if(n_m<1||n_i<1)
                               {sub[n_sub].clear();n_i=0;n_m=0;}
                              else
                              {
                                n_sub++;n_m=0;n_i=0;                               
                              }
                           }  
                        }
                        else
                        {sub[n_sub].clear();n_i=0;n_m=0;}     
                        break;
            case 'M':sub[n_sub]+=s[i];M[n_sub][n_m++]=i;break;
            case 'I':sub[n_sub]+=s[i];I[n_sub][n_i++]=i;break;
            default:sub[n_sub]+=s[i];
           }
        }
       for(int i=0;i<=n_sub;i++)
       {
         cout<<sizeof((M))<<endl;
       }
   }
  cin>>t;
 return 0;
}
