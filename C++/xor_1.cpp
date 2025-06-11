 #include<bits/stdc++.h>
using namespace std;
void findpower(long a[],int i,int j)
{ int p=log(max(a[i],a[j]))/log(2);
  long  n=pow(2,p);
  a[i]^=n;
  a[j]^=n;      
}
int main() 
{   int t;
    cin>>t;
    while(t--)
    {
        long long n,x;
        cin>>n>>x;
        long  a[n];
        for(long long i=0;i<n;i++)
         cin>>a[i];
        long i=0,j=1,count=0;
        int temp;
        while(j<n)
        {   if(a[i]==0)
              {  j++;
                 i++;
              }
            findpower(a,i,j);
            count++;
        }
         for(int i=0;i<n;i++)
         {cout<<a[i]<<" ";}
        cout<<endl;
    }
	return 0;
}
