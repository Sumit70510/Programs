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
};

void print(Node*&head)
 {
    Node *temp=head;
    while(temp!=NULL)
     {
       cout<<temp->data<<"->";
       temp=temp->next; 
     }
     cout<<"NULL"<<endl;
 }

 Node* recursive(Node*&head)
  {
    if(head==NULL||head->next==NULL)
     {
        return head;
     }
    else 
     {
        Node *temphead=recursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return temphead; 
     } 
  }

 void RevRecursive(Node*&head,Node*&curr,Node*&prev)
  {
    //  if(curr==NULL)
    //   {
    //     head=prev;
    //   }
    //  else
    //   {
    //     Node *temp=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=temp;
    //     head=curr;
    //     RevRecursive(head,curr,prev);
    //   }
    //method 2
      if(curr==NULL)
       {head=prev;}
      else
      {
         RevRecursive(head,curr->next,curr);
         curr->next=prev;
      }
    // method 3
     
  }

void reverse(Node*&head,Node*&tail)
 { 
   Node*curr=head,*prev=NULL;
   RevRecursive(head,curr,prev);   
    // Node *temp=head,*prev=NULL,*t2=tail;
    // tail=head;
    // head=t2;
    // while(temp!=NULL)
    //  {  
    //     t2=temp->next;
    //     temp->next=prev;
    //     prev=temp;
    //     temp=t2;
    //  }
 }


void insertion(Node*&head,Node*&tail,int dat)
 {
   Node *temp=new Node(dat); 
   if(head==NULL)
    {
       head=tail=temp; 
    }
   else 
    {
       tail->next=temp;
       tail=temp; 
    } 
 }

int main()
 {
   Node *head=NULL,*tail=NULL;
   for(int i=1;i<7;i++)
    {
      insertion(head,tail,i);  
    }
    print(head);
    reverse(head,tail);
    print(head);
    head=recursive(head);
    print(head);
    return 0; 
 } 