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

bool dfs(vector<vector<int>>&graph,int vertex)
 {
   // cout<<vertex<<endl; 
   visited[vertex]=1; 
   bool f=0;
   for(auto child:graph[vertex])
    { 
       if(child==vertex)
        {cout<<vertex<<"  <==>  "<<vertex<<endl;} 
       if(visited[child])
        continue;
       cout<<"Par : "<<vertex<<"  =>  Child  : "<<child<<endl;
        dfs(graph,child); 
    }
    return 1;
 }
int main()
{
 int v=10,e=9;
 /*
   cout<<"Enter the no. of vrtices : ";
   cin>>v;
 */
 visited= vector<bool>(v,0);
 vector<vector<int>> adj(v);
 addEdge(adj,1,3);
 addEdge(adj,1,5);
 addEdge(adj,3,5);
 addEdge(adj,3,4);
 addEdge(adj,3,6);
 addEdge(adj,3,2);
 addEdge(adj,2,6);
 addEdge(adj,4,6);
 addEdge(adj,5,6);
 addEdge(adj,7,8);
 addEdge(adj,9,9);
 //printgraph(adj,v);
 int connected=0;
 for(int i=1;i<v;i++)
  { 
   if(visited[i])continue;
   dfs(adj,i);
   cout<<endl;
   connected++;
  } 
 cout<<"THE TOTAL NO. OF CONNECTED COMPONENTS ARE : "<<connected; 
 return 0;
} 