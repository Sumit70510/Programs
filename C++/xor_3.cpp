#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll power(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)
        {
            res=res*a;
            n--;
        }
        else
        {
            a=a*a;
            n/=2;
        }
    }
    return res;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
    ll t,n,x,i,j,r,p,z,k,flag,u,arr[10000000];
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(u=0;u<n;u++)
        {
            cin>>arr[u];
        }
        i=0;
        for(k=x;k>0&&i<n-1;k--)
        {
            flag=0;
            p=log(arr[i])/log(2);
            r=power(2,p);
            arr[i]=arr[i]^r;
            for(j=i+1;j<n;j++)
            {
                if(arr[j]^r<arr[j])
                {
                    arr[j]=arr[j]^r;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                arr[n-1]=arr[n-1]^r;
            }
            while(arr[i]<=0)
            {
                i++;
            }
            z=k+1;
        }
        
        if(z>0)
        {
            if(n<3&&z%2>0)
            {
                arr[n-1]=arr[n-1]^1;
                arr[n-2]=arr[n-2]^1;
            }
        }
        
        for(u=0;u<n;u++)
        {
            cout<<arr[u]<<" ";
        }
        cout<<endl;
    }
	return 0;
}