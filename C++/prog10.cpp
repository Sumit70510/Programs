 #include<bits/stdc++.h>
using namespace std;
int n,assigned,post[30],ct,oldct,k=0;
void reassign(int &num,long long a[])
{  for(int t=0;t<assigned;t++)
      {
          if(num%a[post[t]]==0)
          {
              num=(rand()%n+1)+2;
              return(reassign(num,a));
          }
      }
    return;
}
int count(long long b[],int temp)
{    for(int i=temp;i<n;i++)
     if(b[temp]==b[i])
       {post[k++]=i;
        cout<<i<<" : "<<post[k-1]<<endl;}
    return k;
}
void manipulate(long long a[],int temp)
{
     int num=(rand()%n+1)+2;
      reassign(num,a);
     for(int i=oldct,l=1;i<k;i++)
     {a[post[i]]=num*l++; assigned++;}
}
bool check(int temp)
{   for(int i=0;i<oldct;i++)
    {if(temp==post[i])
     {  cout<<"CHECK :- "<<endl;return 0;}
    }
    //cout<<"CHECK :- "<<endl;
   return 1;
}
int main()
{
   int t,i;
   cin>>t;
   while(t--)
	{   oldct=0;ct=0;k=0;
	     assigned=0;
	    cin>>n;
	   long long b[n],a[n];
	    for(i=0;i<n;i++)
	     cin>>b[i];
        for(i=0;i<n;i++)
	     { if(check(i))
	       { ct=count(b,i)-oldct;
	         manipulate(a,i);
	         oldct+=ct;
	       }
	     }
	    for(i=0;i<n;i++)
	     cout<<a[i]<<" ";
	}
	cin>>t;
	return 0;
}
