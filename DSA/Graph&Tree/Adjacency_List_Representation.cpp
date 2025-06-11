#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>>&adj,int u,int v)
 { 
   adj[u].push_back(v);
   adj[v].push_back(u);
 }
void printgraph(vector<vector<int>> &adj,int v)
 {
    for(int i=0;i<v;i++)
     {
        for(int j:adj[i])
         {cout<<j<<" ";}
        cout<<endl;  
     }
 }
int main()
{
  int v=4;
  /*cout<<"Enter the no. of vrtices : ";
  cin>>v;*/
  vector<vector<int>> adj(v);
  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,1,2);
  addEdge(adj,1,3);
  printgraph(adj,v);
  return 0;
} 
