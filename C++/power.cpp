 #include<bits/stdc++.h>
using namespace std;
long long j;
void findpower(long long a[],long long i)
{     long long n;
      for(int k=n=1;k<31;k++)
       { if((n*2>a[i]&&a[i]>=n)||a[i]<=0)
           {break;}
         n*=2;
       } cout<<a[i]<<" ^ "<<n<<" : ";
        a[i]^=n;
       cout<<a[i]<<endl;
       cout<<a[j]<<" ^ "<<n<<" : ";
       if(i>0)
       a[j]^=n;

       cout<<a[j]<<endl;
       if(j-1>i)
         j--;
}
int main()
{   short t;
    cin>>t;
    while(t--)
    {
        long long n,x;
        cin>>n>>x;
        long long a[n],i;
        for(i=0;i<n;i++)
         cin>>a[i];
        long long ct=0;
        j=n-1;i=0;
        bool t1=1;
        while(i<n-1)
        {
            if(t1)
             { j=n-1;t1=0; }
            if(x<n)
             { i=n-x; }
            findpower(a,i); ct++;
            //cout<<"i : "<<i<<endl;;
            if(a[i]==0&&n>2)
             { i++;t1=1;}
            if(ct>=x)
             { break;}
            if(n==2&&(x%2==0))
             {  j=1;findpower(a,0);
               break;
             }
          }
             cout<<endl;
          for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
          cout<<endl;
        }cin>>t;
	return 0;
}
