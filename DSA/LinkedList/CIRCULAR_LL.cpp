
#include<bits/stdc++.h>
using namespace std;

class Node
 {
    public :
     int data;
     Node *next;
     Node(int data)
      {
        this->data=data;
        this->next=NULL;
      }
     Node(int data,Node*ptr)
      {
        this->data=data;
        this->next=ptr;
      }
     ~Node()
      {
        int val=this->data;
        if(next!=NULL)
         {
           delete next;
           next=NULL;
         }
        cout<<"MEMORY FREE FOR DATA "<<this->data<<endl; 
      }
 };

void print(Node*&head)
{ Node*temp=head->next;
  while(temp!=head) 
   {
     cout<<temp->data<<"->";
     temp=temp->next;
   }
   cout<<temp->data<<"->";
   cout<<"NULL\n";
}

void insertnode(Node*&tail,int element,int dat)
 {
    if(tail==NULL)
     {
       Node*temp=new Node(dat);
       temp->next=temp;
       tail=temp;
     }
    else
     { Node *temp=tail;
       while(temp->data!=element)
        {temp=temp->next;}
       Node* node=new Node(dat,temp->next);
       temp->next=node;
       if(temp==tail)
        {tail=node;}
      }  
 }

void deletion(Node*&tail,int element)
 { 
   Node*curr,*prev=tail;
   curr=prev->next;
   while(curr->data!=element)
    {prev=curr;curr=curr->next;} 
   if(prev==curr)
    {tail=NULL;}
   else
    { if(curr==tail)
       {tail=prev;}
      prev->next=curr->next;} 
   curr->next=NULL; 
   delete curr; 
 }
int main()
{
  
  Node *tail;
  tail=NULL;
  int n=7;
  for(int i=1;i<=n;i++)
   {
     insertnode(tail,i-1,i);
   }
   print(tail);
   insertnode(tail,5,10);
   print(tail);
   insertnode(tail,1,11);
   print(tail);
   deletion(tail,5);
   print(tail);
   deletion(tail,7);
   print(tail);
   deletion(tail,1);
   print(tail);
   return 0;
}
