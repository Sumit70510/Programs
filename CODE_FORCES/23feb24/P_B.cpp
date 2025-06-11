#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,k;
       cin>>n>>k;
       vector<long long>a(n),b(n);
       for(long long i=0;i<n;i++)
        {cin>>a[i];}
       for(long long i=0;i<n;i++)
        {cin>>b[i];}
       map<long long,long long> m;
       for(long long i=0;i<n;i++)
        {  
         m[abs(b[i])]+=a[i];
        }
        long long bullets=k;
        for(long long i=1;i<=n;i++)
         { if(m[i]>bullets)
            {cout<<"NO\n";return;}
           bullets-=m[i];
           bullets+=k;
         } 
        cout<<"YES\n";
        return;
}
int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
       solve(); 
     } 
    return 0;
 }