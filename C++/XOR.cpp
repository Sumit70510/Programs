 #include<bits/stdc++.h>
using namespace std;
void findpower(int &a)
{    int n=a,temp;
    while(!(n&&!(n&n-1)))
    {n++;}
    temp=n;n=a;
    while(!(n&&!(n&n-1)))
    {n--;}
    a=min(a^n,a^temp);    
}
int main() 
{   int t;
    cin>>t;
    while(t--)
    {
        long long n,x;
        cin>>n>>x;
        int a[n];
        for(long long i=0;i<n;i++)
         cin>>a[i];
        long i=0,j=1,count=0;
        int temp;
        while(j<n)
        {   findpower(a[i]);
            count++;temp=a[i];
            findpower(a[i]);
            if((temp<=a[i])&&count<x)
              {   j++;
                 i++;
              }
        }
         for(int i=0;i<n;i++)
         {cout<<a[i]<<" ";}
        cout<<endl;
    }
	return 0;
}
