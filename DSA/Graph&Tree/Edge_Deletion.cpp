#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int>SubSum,val;
const long long M=10e9+7;

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
   SubSum[vertex]+=val[vertex];
   for(auto child:graph[vertex])
    {  
        if(child==parent) continue;
        dfs(graph,child,vertex);
        SubSum[vertex]+=SubSum[child];
    }
    return 1;
}

int main()
{
  long long ans=LONG_MIN;
  int v=5,e=9;
  SubSum=vector<int>(v,0);
  val={0,10,5,12,6};
  vector<vector<int>> adj(v);
  addEdge(adj,1,2);
  addEdge(adj,1,4);
  addEdge(adj,4,3);
  
  printgraph(adj,v);
  
  dfs(adj,1);
  
  cout<<"SubTree Sum        : ";
  for(int &i:SubSum)
   {cout<<i<<" ";}
  cout<<endl; 
  
  int index=0;
  
  for(int i=2;i<=v;i++)
   {
     int part1=SubSum[i];
     int part2=SubSum[1]-part1;
     long long temp=(part1*1LL*part2)%M;
     if(temp>ans)
      {
        ans=temp;
        index=i; 
      }
   }
  
  cout<<"MAX PRODUCT OF SUM OF SUBTREES ARE : ";
  cout<<ans<<" , WITH INDEX : "<<index;
  cout<<endl;

 return 0;
} 