#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=110,D=220,E=2*D*D;
int n,a[M][M],c[M][M];
int head[D],cnt,to[E],nxt[E],w[E];
void add(int x,int y,int z){
//	cout<<x<<" -> "<<y<<"   weight : "<<z<<"   jb\n";
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
int ct[D];
void clr(){
	cnt=0;
	ms(head,0);
	ms(ct,0);
}
int q[10000100],dis[D];
bool flag,in[D];
void spfa(){
	int l,r;
	q[l=r=1]=0; ms(in,0);
	ms(dis,1); dis[0]=0; in[0]=1; ms(ct,0);
	while (l<=r){
		int x=q[l++]; in[x]=0;
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (dis[y]>dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				ct[y]=ct[x]+1;
				if (ct[y]>=2*n+1){
					flag=1;
					return ;
				}
				if (!in[y]) q[++r]=y;
			}			
		}
	}
}
void solve(int o){
	clr();
	c[n+1][n+1]=o;
	F(i,1,n){
		if ((i&1)==(n&1)){
			add(0,i+n,9);//x<=0+9
			add(i+n,0,0);//0<=x+0
			add(0,i,0);//x<=0+0
			add(i,0,9);//0<=x+9
		}
		else{
			add(0,i,9);//x<=0+9
			add(i,0,0);//0<=x+0
			add(0,i+n,0);//x<=0+0
			add(i+n,0,9);//0<=x+9
		}
	}
	DF(i,n,1){
		DF(j,n,1){
			c[i][j]=a[i][j]-c[i+1][j]-c[i][j+1]-c[i+1][j+1];
			int x=j,y=i+n;
			if ((i+j)%2==0){
				add(y,x,9-c[i][j]);
				add(x,y,c[i][j]);
			}
			else{
				add(y,x,c[i][j]);
				add(x,y,9-c[i][j]);
			}
		}
	}
	flag=0;
	spfa();
	if (!flag){
		F(i,1,n){
			F(j,1,n){
				int x=j,y=i+n;
				if ((i+j)%2==0){
					c[i][j]+=dis[x]-dis[y];
				}
				else{
					c[i][j]+=dis[y]-dis[x];
				}
			}
		}
		F(i,1,n) c[n+1][i]=abs(dis[i]);
		F(i,n+1,2*n) c[i-n][n+1]=abs(dis[i]);
		F(i,1,n+1){
			F(j,1,n+1){
				cout<<c[i][j];
			}
			cout<<"\n";
		}
		exit(0);
	}
}
int main(){
	n=read();
	F(i,1,n){
		F(j,1,n){
			a[i][j]=read();
		}
	}
//	solve(9);
	F(i,0,9) solve(i);
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
