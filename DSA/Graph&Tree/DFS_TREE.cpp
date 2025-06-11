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
         depth[child-1]=depth[vertex-1]+1;
         dfs(graph,child,vertex);
         height[vertex-1]=max(height[vertex-1],height[child-1]+1);
    }
    
}

int main()
{
  int v=14,e=9;
  height=vector<int>(v-1,0);
  depth=vector<int>(v-1,0);
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
  
  cout<<"Depth  : ";
  for(int &i:depth)
   {cout<<i<<" ";}
  cout<<endl; 

  cout<<"Height : ";
  for(int &i:height)
   {cout<<i<<" ";}
  cout<<endl;

  
 return 0;
} 