#include<iostream>
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

void print(Node* &head)
 {  Node *ptr=head;
    while(ptr!=NULL)
     {
       cout<<ptr->data<<"->";
       ptr=ptr->next;  
     }
     cout<<"NULL"<<endl; 
 }

void insertAthead(Node* &head,Node*&tail,int dat)
 {
   Node *temp=new Node(dat);
   if(head==NULL)
    {
      head=temp;
      tail=temp;
    }
   else
    { 
     temp->next=head;
     head=temp; 
    } 
 }

void insertAttail(Node*&head,Node* &tail,int dat)
 {
   Node *temp=new Node(dat);
   if(tail==NULL)
    {
      head=temp;
      tail=temp;
    } 
   else 
    { 
      tail->next=temp;
      tail=tail->next;
    } 
 }

void insertAtmiddle(Node*&head,Node*&tail,int pos,int dat)
 {
    if(pos==1) 
     {
       insertAthead(head,tail,dat);
       return ;
     }
    Node *temp=head;
    int cnt=1;
    while(cnt<pos-1&&temp->next!=NULL)
     {
       cnt++;
       temp=temp->next;  
     } 
    if(temp->next==NULL)
     { insertAttail(head,tail,dat);
      return;}
    Node *temp2=new Node(dat);
    temp2->next=temp->next;
    temp->next=temp2;  
 }

int main()
{
 int val,n=20,x=21,y=22;
 cout<<"ENTER THE NO. OF ELEMENTS : ";
 //cin>>n;  
 Node *head1,*head2,*tail1,*tail2;
 head1=NULL;
 tail1=head1;
 head2=NULL;
 tail2=head2;
 for(int i=1;i<=n;i++)
  { 
    insertAthead(head1,tail1,i);    
    insertAttail(head2,tail2,i);    
  } 
 cout<<"\nFirst Linked List : ";
 print(head1);
 cout<<"Second Linked List : ";
 print(head2);
//  cout<<"Enter the new Element for middle : ";cin>>x;
//  cout<<"Enter the position for insertion : ";cin>>y;
 insertAtmiddle(head1,tail1,y,x);
 cout<<"First Linked List : ";
 print(head1);
 cout<<"Head : "<<head1->data<<endl;
 cout<<"Tail : "<<tail1->data<<endl;
 insertAtmiddle(head2,tail2,y,x);
 cout<<"Second Linked List : ";
 print(head2);
 cout<<"Head : "<<head2->data<<endl;
 cout<<"Tail : "<<tail2->data<<endl;
return 0;
}