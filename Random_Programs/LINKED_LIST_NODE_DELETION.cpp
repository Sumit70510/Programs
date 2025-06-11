#include<bits/stdc++.h>
using namespace std;
class node
{
 public:
 int n;
 node *next,*previous;
 node()
 { next=NULL;
   previous=NULL;}
}*head,*start,*temper;
 void insert(int item)
 {
      node *input;
      input= new node;
      input->n=item;
      input->next=NULL;
      input->previous=NULL;
      if(head==NULL)
       {start=head=input;}
      else
      {
       head->next=input;
       input->previous=head;
       head=input;
      }
 }
 void display()
 {
     while(head!=NULL)
     {
         cout<<head->n<<" -> ";
         temper=head;
         head=head->next;
      }
      cout<<"!!!\n";
      /*while(temper!=NULL)
      { cout<<temper->n<<"->";
        temper=temper->previous;
       }*/

 }
 void delete1(int key)
  {
    node *temp;
    while(head!=NULL)
    {
        if(head->n==key)
        { temp=head;
          head=head->previous;
          head->next=temp->next;
          delete temp;
          break;
        }
       head=head->next;
    }
  }
int main()
{
  int item;
  char ch;
  head=NULL;
  do
  {cout<<"ENTER THE ELEMENT : ";
   cin>>item;
   insert(item);
   cout<<"DO YOU WANT TO ENTER MORE ELEMENTS (Y/N) : ";
   cin>>ch;
  }while(ch=='Y'||ch=='y');
   node *temp=head;
   head=start;
   cout<<"\nELEMENTS PRESENT IN THE LINKED LISTS ARE :-\n";
   display();
   head=temp;
   cout<<"ENTER THE ELEMENT YOU WANT TO INSERT : ";
   cin>>item;
   insert(item);
   head=start;
   cout<<"\nELEMENTS PRESENT IN THE LINKED LISTS ARE :-\n";
   display();
   int key;
   cout<<"ENTER THE ELEMENT YOU WANT TO DELETE : ";
   cin>>key;
   head=start;
   delete1(key);
   cout<<"LINKED LIST AFTER DELETION OF "<<key<<" :-\n";
   head=start;
   display();
  return 0;
}

