#include<bits/stdc++.h>
using namespace std;

class disjointSet
{
   vector<int>parent,rank,size;
   public:
   //*
    disjointSet(int n)
    {
     parent=vector<int>(n+1);
     rank=vector<int>(n+1,0);
     size=vector<int>(n+1,1);
     for(int i=0;i<=n;i++)
      {
       parent[i]=i; 
      }
    }
   int findUParent(int u)
    {
      if(parent[u]==u)
       {return u;}
      return parent[u]=findUParent(parent[u]); 
    }
   //*/   
   void unionByRank(int u,int v)
    {
      int ulp_u=findUParent(u);
      int ulp_v=findUParent(v);
      if(ulp_u==ulp_v) return;
      if(rank[ulp_u]<rank[ulp_v])
       {
         parent[ulp_u]=ulp_v;  
       }
      else
       {
         if(rank[ulp_v]<rank[ulp_u])
          {
            parent[ulp_v]=ulp_u;  
          }
         else
          {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;  
          }  
       } 
    }
    //*/
   void unoinBySize(int u,int v)
    {
       int ulp_u=findUParent(u);
       int ulp_v=findUParent(v);
       if(ulp_u==ulp_v) return;
       if(size[ulp_u]<size[ulp_v])
        {
          parent[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u]; 
        }
       else 
        {
          parent[ulp_v]=ulp_u;
          size[ulp_u]+=size[ulp_v];
        } 
    }  

   void sameComponent(int u,int v)
    {
       if(findUParent(u)==findUParent(v))
        {cout<<"SAME"<<endl;}
       else 
        {cout<<"NOT SAME"<<endl;} 
    }   
};
int main()
{
  disjointSet ds(7);
//   ds.unionByRank(1,2);
//   ds.unionByRank(2,3);
//   ds.unionByRank(4,5);
//   ds.unionByRank(6,7);
//   ds.unionByRank(5,6);
  ds.unoinBySize(1,2);
//   ds.sameComponent(2,5);
  ds.unoinBySize(2,3);
  ds.unoinBySize(4,5);
  ds.unoinBySize(6,7);
  ds.unoinBySize(5,6);
  ds.sameComponent(3,7);
//   ds.unionByRank(3,7);
  ds.unoinBySize(3,7);
  ds.sameComponent(3,7);
  return 0; 
}