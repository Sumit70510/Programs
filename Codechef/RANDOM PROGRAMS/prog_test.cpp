#include <bits/stdc++.h>
using namespace std;
void solve();
#define ll long long

int main() {
	int t;cin>>t;
	while(t--) solve();
}

void solve(){
    int n;cin>>n;
    
    if(n%2==0 || n%5 ==0) cout<<"NO\n";
    else cout<<"YES\n";
unsigned long long int x=1;
  int count=0;
  while(count<250)
   {  if(x%n==0)
       {
          cout<<" X : "<<x<<endl; 
          break;
       }
       else
        { cout<<" no "<<endl;
            x*=10;
          x++; 
        }
       count++; 
   } 
   cout<<"not found "<<x<<endl;   
}
