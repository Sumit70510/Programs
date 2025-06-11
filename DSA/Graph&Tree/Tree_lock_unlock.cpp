#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>nodes;
map<int,int>locklogs;
vector<vector<int>>tree
vector<int>path,status;

void ComputePath(int X,int parent=-1)
{
  path[X]=parent;
  for(auto &child:Tree[X])
   {
     dfs(child,X);
   }
}

void CreateTree(int n,int m)
{
  int count=1;  
  for(int i=1;count<=n;i++)
   {
     for(int j=count;j<(count+m)&&j<=n;j++)
      {
        tree[i].push_back(j);
      }
     count+=m;  
   }
}

void freezePath(int X)
{
  int v=X;
  while(v!=-1)
   {
     status[v]=1;
     v=tree[v];
   } 
}

void blockBelow(int X,int n=2)
{
  status[X]=n;
  for(auto &child:Tree[X])
   {
     blockBelow(child);
   }  
}

bool lock(int X,int uid)
{
   if(status[X]!=0)
    {
      return 0;
    }
   else 
    {
      freezePath(X);
      blockBelow(X);
      status[X]=3;
      locklogs[X]=uid;
    } 
}

bool unlock(int X,int uid)
{
  if(locklogs.find(X)!=locklogs.end()&&locklogs[X]==uid)
   {
    blockBelow(X,0); 
    return 1;
   }
  return 0; 
}
vector<int>data;
bool checkLockedDescendants(int X, int uid) {
    bool hasLockedDescendant = false;
    for (auto &child : tree[X]) {
         if (status[child] == 3) {
            if (locklogs[child] != uid) return false; 
            hasLockedDescendant = true; 
          }
        if (!checkLockedDescendants(child, uid)) return false;
    }
    return hasLockedDescendant;
}

bool upgrade(int X, int uid) {
    if (status[X] == 3) {
        return false; 
    }
   if (!checkLockedDescendants(X, uid)) {
        return false; 
    }
    status[X] = 3;
    blockBelow(X, 2);
    locklogs[X] = uid;
    return true;
}

int main()
{
  int n,m,q;
  cin>>n>>m>>q;
  tree=vector<vector<int>>(n+1);
  path=vector<int>(n+1);
  status=vector<int>(n+1);
  string temp;
  for(int i=0;i<n;i++)
   {
     cin>>temp;
     nodes[temp]=i+1;
   }
  CreateTree(n,m);
  ComputePath();
  bool f=0;
  int type,uid;
  string name;
  while(q--)
   {
     cin>>type>>name>>uid;
     switch(type)
      {
        case 1:f=lock(nodes[name],uid);break;
        case 2:f=unlock(nodes[name],uid);break;
        case 3:f=upgrade(nodes[name],uid);break;
      }
     if(f)
      {cout<<"true"<<endl;}
     else
      {cout<<"false"<<endl;}   
   }
  return 0;  
}