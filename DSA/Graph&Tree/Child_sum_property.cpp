#include<bits/stdc++.h>
using namespace std;

class Node{
 public :
  int key;
  Node *left;
  Node *right;
  Node(int val)
   {
     key=val;
     right=left=NULL;
   }
};
bool f=0;
int dfs(Node*root)
{
  if(root==NULL)
   {return 0;}
  int l=0,r=0;
  l=dfs(root->left);
  r=dfs(root->right);
  if(l==-1||r==-1)
   return -1;
  return (abs(l-r)<=1)? max(l,r)+1 : -1; 
}
void in(Node*root)
 {
    if(root==NULL)
     {return;}
    cout<<root->key<<" ";
    in(root->left); 
    in(root->right); 
 }

int main()
{ 
   Node root(3);
   root.left=new Node(4);
   root.left->left=new Node(5);
   root.left->right=new Node(9);
   root.right=new Node(8);
   root.right->right=new Node(7);
   root.right->left=new Node(6);
   root.right->right->right=new Node(6);
   Node *cpy=&root;
   in(cpy);
   cout<<endl;
   cout<<dfs(cpy);
   return 0; 
}