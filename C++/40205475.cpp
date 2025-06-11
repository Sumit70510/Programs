#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define repu(v,s,e) for(ll v=s;v<e;v++)
#define repd(v,s,e) for(ll v=s;v>e;v--)
#define min(x,y) ((x)<(y)?(x):(y))
ll q,ss,e,gg,g;
ll power(ll x,ll y,ll mod){
    if(y>=mod-1)
        y%=(mod-1);
    if(x>=mod)
        x%=mod;
    ll ret=1;
    while(y>0){
        if(y&1) ret=ret*x;
        x*=x;
        if(ret>=mod) ret%=mod;
        if(x>=mod) x%=mod;
        y>>=1;
    }
    return ret;
}
ll convertx2e(ll x, ll& e) 
{
    e=0; 
    while(x%2==0){
        x>>=1; 
        e++; 
    }
    return x; 
} 
ll solve(ll a,ll p){
    if(a==1) return 1;
    if(p%4==3) return power(a,(p+1)/4,p);
    //ll test=power(a,(p-1)/(1<<e),p);
    //if(test==1) return power(a,(p+(1<<e)-1)/(1<<(e+1)),p);
    //if(test==p-1) return (power(q,(p-1)/4,p)*power(a,(p+(1<<e)-1)/(1<<(e+1)),p))%p; 
    ll temp=power(a,ss/2,p);
    ll x=(temp*a)%p; 
    ll b=(x*temp)%p;
    g=gg; 
    ll r=e;
    while(true){ 
        /*ll m=0,t=b;
        for(;m<r;m++){
            if(t==1)
                break;
            t=(t*t)%p;
        }
        if(m==0)
            break;
        if(m==r)
            return -1;
        ll tmp=power(g,1<<(r-m-1),p);
        x=(x*tmp)%p; 
        g=(tmp*tmp)%p; 
        b=(b*g)%p;
        r=m;
        */
        if(b==1)
            return x;
        ll m=1;
        for(;m<r;m++)
            if(power(b,(1<<m),p)==1)
                break;
        if(m==r)
            break;
        ll tmp=power(g,1<<(r-m-1),p);
        x=(x*tmp)%p; 
        g=(tmp*tmp)%p; 
        b=(b*g)%p;
        r=m;
    }
    return -1;
}
void dfs(int v,int par,vector<vector<ll> >& adj,ll c[],ll a[],ll s[],ll& count,ll n,ll mod,ll p){
    s[v]=0;
    ll c_sq_sum=0;
    for(int ch : adj[v])
        if(ch!=par){
            dfs(ch,v,adj,c,a,s,count,n,mod,p);
            if(count==-1) return;
            s[v]=(s[v]+s[ch])%p;
            c_sq_sum=(c_sq_sum+s[ch]*s[ch])%p;
        }
    ll val=(c[v]+c_sq_sum)%p;
    //cout<<v<<" --> "<<val<<"\n";
    if(val==0){
        a[v]=(p*n - s[v])%p;
        s[v]=(s[v]+a[v])%p;
    }
    else{
        if(power(val,(p-1)/2,p)!=1){
            count=-1;
            return;
        }
        count++;
        ll res=solve(val,p);
        if(res==-1){
            count=-1;
            return;
        } 
        //cout<<v<<" ---- "<<res<<"\n";
        a[v]=(p*n + res - s[v])%p;
        s[v]=(s[v]+a[v])%p;
    }
    //cout<<v<<" "<<a[v]<<"\n";
}
int main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        ss=convertx2e(p-1,e);
        q=2;
        while(1){
            if(power(q,(p-1)/2,p)==(p-1)) 
                break;
            q++;
        }
        gg=power(q,ss,p);
        ll mod=998244353;
        ll c[n+1],a[n+1],s[n+1],count=0;
        vector<vector<ll> > adj(n+1);
        repu(v,2,n+1){
            ll u;
            cin>>u;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        repu(i,1,n+1) cin>>c[i];
        dfs(1,0,adj,c,a,s,count,n,mod,p);
        if(count==-1)
            cout<<"0\n-1\n";
        else{
            cout<<power(2,count,mod)<<"\n";
            repu(i,1,n+1) cout<<a[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}