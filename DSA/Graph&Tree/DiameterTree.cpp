#include<iostream>
#include<vector>
using namespace std;

vector<int>height,depth;

void addEdge(vector<vector<int>>&adj,int u,int v)
 { 
   adj[u].push_back(v);
   if(u!=v)
   adj[v].push_back(u);
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

bool dfs(vector<vector<int>>&graph,int vertex,int parent=0)
{
   for(auto child:graph[vertex])
    {  
        if(child==parent) continue;
         depth[child]=depth[vertex]+1;
         dfs(graph,child,vertex);
    }
    return 0;
}

int main()
{
  int v=14,e=9;

  height=vector<int>(v,0);
  depth=vector<int>(v,0);
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
  
  int mx_depth=-1;
  int mx_Node;
  int mx_Node2;

  cout<<"Depth  : ";
  for(int i=1;i<depth.size();i++)
   {cout<<depth[i]<<" ";
    if(depth[i]>=mx_depth)
     {
      mx_depth=depth[i];
      mx_Node= i;
     }
    depth[i]=0; 
   }
  cout<<endl; 
  cout<<"Max Depth : "<<mx_depth<<endl;
  cout<<"Max Node  : "<<mx_Node<<endl;
 
  int diameter=-1;
  dfs(adj,mx_Node);
  for(int i=1;i<depth.size();i++)
   {
     if(diameter<=depth[i])
      {
        diameter=depth[i];
        mx_Node2=i;
      }
   }
  cout<<"Diameter of this Tree With Nodes {"<<mx_Node<<","<<mx_Node2<<"} : "<<diameter<<endl; 
  return 0;
} 