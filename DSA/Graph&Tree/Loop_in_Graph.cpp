#include<iostream>
#include<vector>
using namespace std;

vector<bool> visited;

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

bool dfs(vector<vector<int>>&graph,int vertex,int Par)
{
// cout<<vertex<<endl; 
   visited[vertex]=1; 
   bool f=0;
   for(auto child:graph[vertex])
    { 
    //    if(child==vertex)
    //     {cout<<vertex<<"  <==>  "<<vertex<<endl;} 
       if(visited[child]&&child==Par)  continue;
       if(visited[child]) return true;
        // cout<<"Par : "<<vertex<<"  =>  Child  : "<<child<<endl;
        f|=dfs(graph,child,vertex); 
    }
    
    return f;
}


int main()
{
  int v=10,e=9;
  /*cout<<"Enter the no. of vrtices : ";
  cin>>v;*/
  visited= vector<bool>(v,0);
  vector<vector<int>> adj(v);
//   addEdge(adj,1,3);
//   addEdge(adj,1,5);
//   addEdge(adj,3,5);
//   addEdge(adj,3,4);
//   addEdge(adj,3,6);
//   addEdge(adj,3,2);
//   addEdge(adj,2,6);
//   addEdge(adj,4,6);
//   addEdge(adj,5,6);
//   addEdge(adj,7,8);
//   addEdge(adj,9,9);
  addEdge(adj,1,2);
  addEdge(adj,2,3);
  addEdge(adj,3,1);
  printgraph(adj,v);
 bool loop=0;
 for(int i=1;i<v;i++)
  { 
    if(visited[i])continue;
    if(dfs(adj,i,1))
     {
       loop=1;
       break;
     }
  } 
 cout<<loop;
 return 0;
} 
