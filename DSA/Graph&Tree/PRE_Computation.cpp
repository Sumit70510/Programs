#include<iostream>
#include<vector>
using namespace std;

vector<int>SubSum,EvenCount;

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
   if(vertex%2==0)
    {EvenCount[vertex]++;}
   SubSum[vertex]+=vertex;
   for(auto child:graph[vertex])
    {  
        if(child==parent) continue;
        dfs(graph,child,vertex);
        SubSum[vertex]+=SubSum[child];
        EvenCount[vertex]+=EvenCount[child];         
    }
    
}
int main()
{
  int v=14,e=9;
  SubSum=vector<int>(v,0);
  EvenCount=vector<int>(v,0);
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
  
  cout<<"SubTree Sum        : ";
  for(int &i:SubSum)
   {cout<<i<<" ";}
  cout<<endl; 

  cout<<"SubTree Even Count : ";
  for(int &i:EvenCount)
   {cout<<i<<" ";}
  cout<<endl;

  
 return 0;
} 