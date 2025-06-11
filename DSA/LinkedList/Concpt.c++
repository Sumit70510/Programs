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
 
int main()
 {
   Node *head=new Node(20);
   print(head);   
   head=head->next;
   print(head);   
   head=head->next;
   cout<<"->";
   cout<<head->data<<" "<<head->next;
   print(head);   
   return 0;
 }