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
bool dfs(Node*root)
{
  if(root==NULL||(root->left==NULL&&root->right==NULL))
   {return true;}
  int sum=0;
  if(root->left!=NULL)
   {sum+=root->left->key;}
  if(root->right!=NULL)
   {sum+=root->right->key;}
  return (sum==root->key)&&(dfs(root->left)&&dfs(root->right));
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
   Node root(20);
   root.left=new Node(8);
   root.right=new Node(12);
   root.right->left=new Node(3);
   root.right->right=new Node(9);
   Node *cpy=&root;
   in(cpy);
   cout<<endl;
   cout<<dfs(cpy);
   return 0; 
}