#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int>visited;
vector<pair<int,int>>order;
vector<int>level;

void BFS(int start)
{
  queue<int> q;
  q.push(start);
  visited[start]=1;
  order.push_back({level[start],start});
  while(!q.empty())
   {
     int temp=q.front();
     q.pop();
     for(auto &child:graph[temp])
      {
        if(visited[child]) continue;
        visited[child]=1;
        q.push(child);
        level[child]=level[temp]+1;
        order.push_back({level[child],child}); 
      } 
   }
}

void Insert(int u,int v)
{
  graph[u].push_back(v);
  if(u!=v)
  graph[v].push_back(u);
}

int main()
{
  int v;
  graph=vector<vector<int>>(v);
  visited=vector<int>(v,0);
  level=vector<int>(v,1);
  Insert(1,2);
  Insert(1,3);
  Insert(1,13);
  Insert(2,5);
  Insert(5,6);
  Insert(5,7);
  Insert(5,8);
  Insert(8,12);
  Insert(3,4);
  Insert(4,9);
  Insert(4,10);
  Insert(10,11);
  
  BFS(1);
  cout<<"Order is : ";
  int prev=0;
  for(auto & i : order)
   {
     if(i.first>prev)
      {cout<<"\nLevel "<<i.first<<endl;prev++;}
     cout<<i.second<<" ";
   }
  cout<<endl; 
  return 0;  
}