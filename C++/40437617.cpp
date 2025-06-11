#include <bits/stdc++.h>
using namespace std;

void solve()
{
   string str;
   cin>>str;
   int total=0;
   for(int i=0;i<str.size();i++)
   {
        vector<int> check;
        int a=0,b=0,c=0,d=0,e=0,current=0;
        for(int j=0;j<i+1;j++)
        {
            if (str[j]=='0')
            {
                if(current%2==0)
                e++;
                else
                d++;
                a++;
                c++;
            }
            else
            {
                check.push_back(a);
                a=0;
                current++;
                b++;
            }
    
        }
        check.push_back(a);
        
        set<pair<pair<int,int>,pair<int,int>>> bind;
        bind.insert(make_pair(make_pair(b,c),make_pair(d,e)));
        for(int k=i+1;k<str.size();k++)
        {
            if(str[k-(i+1)]=='1')
            {
                check.erase(check.begin());
                int temp=e;
                e=d;
                d=temp;
                b--;
            }
            else
            {
                c--;
                check[0]--;
                e--;
            }
            if(str[k]=='1') 
            {
                b++;
                check.push_back(0);
            }
            else
            {
                c++;
                check[check.size()-1]++;
                if(check.size()%2==1)
                e++;
                else
                d++;
            }
            bind.insert(make_pair(make_pair(b,c),make_pair(d,e)));
        }
        total=bind.size()+total;
   }
   cout<<total<<endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   int ch=0;
   cin>>t;
   while(t--)
   {
      solve();
      ch+=1;
   }
   return 0;
}