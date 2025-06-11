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

void mid(Node*&head)
 {
   if(head==NULL)
    { cout<<"NULL"<<endl;       
        return;}
   else 
     { if(head->next==NULL)
        {
          cout<<"Mid of the LL is : "<<head->data<<endl;
          return;    
        }
       else
        { 
        if(head->next->next==NULL)
         {
          cout<<"Mid of the LL is : "<<head->next->data<<endl;
          return;          
         }
        } 
     }  
   Node*T1=head,*T2=head->next;
   while(T2!=NULL)
    {
      T1=T1->next;  
      T2=T2->next;
      if(T2!=NULL)
       {T2=T2->next;}
    }
    cout<<"Mid of the LL is : "<<T1->data<<endl;  
 }

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
   for(int i=1;i<6;i++)
    {
      insertion(head,tail,i);  
    }
    print(head);
    mid(head);
    return 0; 
 } 