#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int>parent;

void addEdge(vector<vector<int>>&adj,int u,int v)
 { 
   adj[u].push_back(v);
  //  if(u!=v)
  //  adj[v].push_back(u);
 }

void printgraph(vector<vector<int>> &adj,int v)
 {
    for(int i=1;i<v;i++)
     { cout<<i<<" :  ";
        for(int j:adj[i])
         {cout<<j<<" ";}
        cout<<endl;  
     }
 }

bool dfs(vector<vector<int>>&graph,int vertex,int par=-1)
{
   parent[vertex]=par; 
   for(auto child:graph[vertex])
    {  
        // if(child==par) continue;
        dfs(graph,child,vertex);
    }
    return 0;
}

vector<int> path(int v)
 {
   vector<int> ans;
   while(v!=-1)
    {
        ans.push_back(v);
        v=parent[v];
    }
   reverse(ans.begin(),ans.end()); 
   for(auto &i:ans)
    {cout<<i<<" ";}
    cout<<endl;
   return ans;
 }

int main()
{
  int v=14,e=9;

  parent=vector<int>(v,0);
  vector<vector<int>> adj(v);
  
  addEdge(adj,1,2);
  addEdge(adj,1,3);
  addEdge(adj,1,13);
  addEdge(adj,2,5);
  addEdge(adj,3,4);
  addEdge(adj,5,6);
  addEdge(adj,5,7);
  addEdge(adj,5,8);
  addEdge(adj,8,12);
  addEdge(adj,4,9);
  addEdge(adj,4,10);
  addEdge(adj,10,11);

  printgraph(adj,v);

  dfs(adj,1);

  int x,y;

  cin>>x>>y;
  vector<int> path_x=path(x);
  vector<int> path_y=path(y);

  int mn=min(path_x.size(),path_y.size());

  int lca=-1;

  for(int i=0;i<mn;i++)
   {
      if(path_x[i]==path_y[i])
       {lca=path_x[i];}
      else
       break; 
   }
  cout<<"LCA OF THESE NODES ARE : "<<lca<<endl;
  return 0;
} 